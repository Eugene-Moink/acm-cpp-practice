# -*- coding: utf-8 -*-
"""业务流程图绘制库：按课本图 4-3 的六种基本符号绘制（黑白、宋体）。"""
import os
import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle, Polygon, Circle
from matplotlib.font_manager import FontProperties

DPI = 300
SUN = r'C:\Windows\Fonts\simsun.ttc'
BLACK = '#000000'


def fp(size):
    return FontProperties(fname=SUN, size=size)


class Canvas:
    def __init__(self, w, h):
        self.W, self.H = w, h
        self.fig = plt.figure(figsize=(w / DPI, h / DPI), dpi=DPI)
        self.ax = self.fig.add_axes([0, 0, 1, 1])
        self.ax.set_xlim(0, w)
        self.ax.set_ylim(0, h)
        self.ax.set_aspect('equal')
        self.ax.axis('off')

    # ---------- 基本图元 ----------
    def text(self, x, y, s, size=10, ha='center', va='center', rot=0, z=8):
        self.ax.text(x, y, s, fontproperties=fp(size), ha=ha, va=va,
                     color=BLACK, linespacing=1.42, rotation=rot, zorder=z)

    def func_box(self, cx, cy, w, h, num, s, size=10, band=0.30, numsize=None,
                 lw=1.5):
        """业务功能描述：矩形上带一条横线，横线上方写标识（编号）。"""
        x0, y0 = cx - w / 2, cy - h / 2
        bh = h * band
        self.ax.add_patch(Rectangle((x0, y0), w, h, facecolor='white',
                                    edgecolor=BLACK, lw=lw, zorder=5))
        self.ax.plot([x0, x0 + w], [cy + h / 2 - bh] * 2, color=BLACK, lw=lw,
                     zorder=6)
        self.text(cx, cy + h / 2 - bh / 2, num, size=numsize or size)
        if s:
            self.text(cx, cy - bh / 2 + h * 0.02, s, size=size)
        return dict(x0=x0, x1=x0 + w, y0=y0, y1=y0 + h, cx=cx, cy=cy)

    def doc_box(self, cx, cy, w, h, s, size=10, lw=1.5):
        """各类单证、报表：下边为波浪线的矩形。"""
        x0, x1 = cx - w / 2, cx + w / 2
        top, base = cy + h / 2, cy - h / 2
        t = np.linspace(0, 1, 80)
        xs = x0 + t * w
        ys = base + h * (0.08 + 0.14 * t - 0.09 * np.sin(2 * np.pi * t))
        pts = [(x0, top), (x1, top)]
        pts += list(zip(xs[::-1], ys[::-1]))
        self.ax.add_patch(Polygon(pts, closed=True, facecolor='white',
                                  edgecolor=BLACK, lw=lw, zorder=5))
        self.text(cx, cy + h * 0.10, s, size=size)
        return dict(x0=x0, x1=x1, y0=base, y1=top, cx=cx, cy=cy)

    def store_box(self, cx, cy, w, h, s, size=10, lw=1.5):
        """数据存储或文档：右侧开口的矩形。"""
        x0, x1 = cx - w / 2, cx + w / 2
        y0, y1 = cy - h / 2, cy + h / 2
        self.ax.add_patch(Polygon([(x0, y0), (x1, y0), (x1, y1), (x0, y1)],
                                  closed=True, facecolor='white',
                                  edgecolor='none', zorder=5))
        for seg in ([(x0, y1), (x1, y1)], [(x0, y1), (x0, y0)],
                    [(x0, y0), (x1, y0)]):
            self.ax.plot([seg[0][0], seg[1][0]], [seg[0][1], seg[1][1]],
                         color=BLACK, lw=lw, zorder=6,
                         solid_capstyle='butt')
        self.text(cx, cy, s, size=size)
        return dict(x0=x0, x1=x1, y0=y0, y1=y1, cx=cx, cy=cy)

    def circle_node(self, cx, cy, r, s, size=10, lw=1.5):
        """客观实体 / 人：圆形。"""
        self.ax.add_patch(Circle((cx, cy), r, facecolor='white',
                                 edgecolor=BLACK, lw=lw, zorder=5))
        if s:
            self.text(cx, cy, s, size=size)
        return dict(cx=cx, cy=cy, r=r)

    # ---------- 箭头 ----------
    def arrow(self, pts, dashed=False, lw=1.4, hl=20, hw=13, z=4):
        pts = [tuple(map(float, p)) for p in pts]
        (px, py), (ex, ey) = pts[-2], pts[-1]
        dx, dy = ex - px, ey - py
        L = (dx * dx + dy * dy) ** 0.5
        ux, uy = dx / L, dy / L
        bx, by = ex - ux * hl, ey - uy * hl
        pts[-1] = (bx, by)
        xs = [p[0] for p in pts]
        ys = [p[1] for p in pts]
        ls = (0, (5, 3)) if dashed else '-'
        self.ax.plot(xs, ys, color=BLACK, lw=lw, ls=ls, zorder=z,
                     solid_capstyle='butt', dash_capstyle='butt')
        tri = [(ex, ey), (bx - uy * hw / 2, by + ux * hw / 2),
               (bx + uy * hw / 2, by - ux * hw / 2)]
        self.ax.add_patch(Polygon(tri, closed=True, facecolor=BLACK,
                                  edgecolor=BLACK, lw=0, zorder=z + 1))

    def save(self, path):
        import time
        tmp = path + '.tmp.png'
        self.fig.savefig(tmp, dpi=DPI, facecolor='white')
        plt.close(self.fig)
        for i in range(12):
            try:
                os.replace(tmp, path)
                break
            except OSError:
                time.sleep(0.6)
        else:
            raise OSError('cannot replace %s' % path)
        print('saved', path)
