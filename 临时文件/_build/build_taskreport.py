# -*- coding: utf-8 -*-
"""
以《实验一、蛮力算法的设计与性能分析.docx》（任务书/填空模板）为版式，
把实验要求的全部内容补齐，生成任务书版实验报告。

来源：附件副本（只读，原工作区文件被 Word 占用）
输出：干林锋-实验一-蛮力算法的设计与性能分析-实验报告（任务书版）.docx
"""
import os
import io
import docx
from docx.shared import Pt, Cm
from docx.oxml import OxmlElement
from docx.oxml.ns import qn
from docx.text.paragraph import Paragraph

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
SRC = (r"C:\Users\墨轩\.dsh\attachments\v1\files\3a"
       r"\3afa391f60f191029318e7b0e8055d9173a3b819cdff837c9e2a973f5958078f"
       r"\实验一、蛮力算法的设计与性能分析.docx")
OUT = os.path.join(ROOT, "干林锋-实验一-蛮力算法的设计与性能分析-实验报告（任务书版）.docx")
IMGDIR = os.path.join(ROOT, "img")

SONG, HEI, EN, MONO = "宋体", "黑体", "Times New Roman", "Consolas"
ANS = 12.0      # 正文答案（小四）
CODE = 8.0      # 代码
TBL = 10.0      # 表格正文
CAP = 10.0      # 图表题注

doc = docx.Document(SRC)
body = doc.element.body
CH = list(body)          # 原始子元素快照（引用在增删过程中保持有效）
# 模板原有的两张测试用例表必须先取到引用（后续会插入新表，doc.tables 顺序会变）
ORIG_T1 = doc.tables[0]
ORIG_T2 = doc.tables[1]


# ----------------------------------------------------------------- 低层构造
def make_run(par_el, text, cn=SONG, en=EN, size=ANS, bold=False):
    r = OxmlElement("w:r")
    rPr = OxmlElement("w:rPr")
    rFonts = OxmlElement("w:rFonts")
    rFonts.set(qn("w:ascii"), en)
    rFonts.set(qn("w:hAnsi"), en)
    rFonts.set(qn("w:eastAsia"), cn)
    rFonts.set(qn("w:cs"), en)
    rPr.append(rFonts)
    if bold:
        rPr.append(OxmlElement("w:b"))
    for tag in ("w:sz", "w:szCs"):
        e = OxmlElement(tag)
        e.set(qn("w:val"), str(int(round(size * 2))))
        rPr.append(e)
    r.append(rPr)
    t = OxmlElement("w:t")
    t.set(qn("xml:space"), "preserve")
    t.text = text
    r.append(t)
    par_el.append(r)


def make_par_xml(align=None, ind_pt=0, before=0, after=0, line=1.25, keep_next=False):
    p = OxmlElement("w:p")
    pPr = OxmlElement("w:pPr")
    p.append(pPr)
    if keep_next:
        pPr.append(OxmlElement("w:keepNext"))
    sp = OxmlElement("w:spacing")
    sp.set(qn("w:before"), str(int(round(before * 20))))
    sp.set(qn("w:after"), str(int(round(after * 20))))
    sp.set(qn("w:line"), str(int(round(line * 240))))
    sp.set(qn("w:lineRule"), "auto")
    pPr.append(sp)
    if ind_pt:
        ind = OxmlElement("w:ind")
        ind.set(qn("w:firstLine"), str(int(round(ind_pt * 20))))
        pPr.append(ind)
    if align:
        jc = OxmlElement("w:jc")
        jc.set(qn("w:val"), align)
        pPr.append(jc)
    return p


class Cur:
    """插入游标：始终指向最后一个已插入的元素"""

    def __init__(self, el):
        self.el = el

    def _ins(self, new):
        self.el.addnext(new)
        self.el = new
        return new

    def p(self, text="", size=ANS, bold=False, cn=SONG, en=EN, align=None,
          indent_chars=0, before=0, after=0, line=1.25, keep_next=False):
        el = make_par_xml(align=align, ind_pt=size * indent_chars, before=before,
                          after=after, line=line, keep_next=keep_next)
        self._ins(el)
        if text:
            make_run(el, text, cn, en, size, bold)
        return self

    def p_mixed(self, parts, size=ANS, align=None, indent_chars=0, after=0, line=1.25):
        """parts: [(text, bold, cn, size_or_None), ...]"""
        el = make_par_xml(align=align, ind_pt=size * indent_chars, after=after, line=line)
        self._ins(el)
        for text, bold, cn, sz in parts:
            make_run(el, text, cn, EN, sz or size, bold)
        return self

    def code(self, code_text, size=CODE):
        for ln in code_text.split("\n"):
            self.p(ln, size=size, cn=SONG, en=MONO, align="left", line=1.0)
        return self

    def table(self, headers, rows, widths, caption=None, size=TBL, header_size=None,
              aligns=None, caption_before=8):
        if caption:
            self.p(caption, size=CAP, bold=True, cn=HEI, align="center",
                   before=caption_before, after=2, line=1.0, keep_next=True)
        t = doc.add_table(rows=len(rows) + 1, cols=len(headers))
        set_table_borders(t)
        apply_table_geometry(t, widths)
        hs = header_size or size
        for i, h in enumerate(headers):
            fmt_cell(t.cell(0, i), h, size=hs, bold=True, cn=HEI, align="center")
        if aligns is None:
            aligns = ["center"] * len(headers)
        for ri, row in enumerate(rows, start=1):
            for ci, val in enumerate(row):
                fmt_cell(t.cell(ri, ci), str(val), size=size, align=aligns[ci])
        self.el.addnext(t._tbl)
        self.el = t._tbl
        self.p("", size=6, line=1.0, after=2)
        return self

    def fig(self, imgname, caption, width_cm):
        el = make_par_xml(align="center", before=6, after=2, line=1.0, keep_next=True)
        self._ins(el)
        run = Paragraph(el, doc).add_run()
        run.add_picture(os.path.join(IMGDIR, imgname), width=Cm(width_cm))
        self.p(caption, size=CAP, align="center", after=8, line=1.0)
        return self


def apply_table_geometry(t, widths):
    t.autofit = False
    tblPr = t._tbl.tblPr
    for tag in ("w:tblW", "w:tblLayout"):
        for old in tblPr.findall(qn(tag)):
            tblPr.remove(old)
    tblW = OxmlElement("w:tblW")
    tblW.set(qn("w:w"), str(int(sum(widths) * 567)))
    tblW.set(qn("w:type"), "dxa")
    tblPr.append(tblW)
    layout = OxmlElement("w:tblLayout")
    layout.set(qn("w:type"), "fixed")
    tblPr.append(layout)
    normalize_tblPr(t)
    for i, w in enumerate(widths):
        t.columns[i].width = Cm(w)
    for r in t.rows:
        for i, w in enumerate(widths):
            r.cells[i].width = Cm(w)


TBLPR_ORDER = ["tblStyle", "tblpPr", "tblOverlap", "bidiVisual", "tblStyleRowBandSize",
               "tblStyleColBandSize", "tblW", "jc", "tblCellSpacing", "tblInd",
               "tblBorders", "shd", "tblLayout", "tblCellMar", "tblLook", "tblCaption",
               "tblDescription"]


def normalize_tblPr(table):
    tblPr = table._tbl.tblPr
    children = list(tblPr)
    for el in children:
        tblPr.remove(el)

    def key(el):
        tag = el.tag.split("}")[-1]
        return TBLPR_ORDER.index(tag) if tag in TBLPR_ORDER else len(TBLPR_ORDER)

    for el in sorted(children, key=key):
        tblPr.append(el)


def set_table_borders(table, sz=4):
    tblPr = table._tbl.tblPr
    for old in tblPr.findall(qn("w:tblBorders")):
        tblPr.remove(old)
    borders = OxmlElement("w:tblBorders")
    for edge in ("top", "left", "bottom", "right", "insideH", "insideV"):
        e = OxmlElement("w:" + edge)
        e.set(qn("w:val"), "single")
        e.set(qn("w:sz"), str(sz))
        e.set(qn("w:space"), "0")
        e.set(qn("w:color"), "auto")
        borders.append(e)
    tblPr.append(borders)


def fmt_cell(cell, text, size=TBL, bold=False, cn=SONG, align=None):
    p = cell.paragraphs[0]
    for r in list(p.runs):
        r._element.getparent().remove(r._element)
    pPr = p._element.get_or_add_pPr()
    for tag in ("w:spacing", "w:jc"):
        for old in pPr.findall(qn(tag)):
            pPr.remove(old)
    sp = OxmlElement("w:spacing")
    sp.set(qn("w:before"), "20")
    sp.set(qn("w:after"), "20")
    sp.set(qn("w:line"), "240")
    sp.set(qn("w:lineRule"), "auto")
    pPr.append(sp)
    if align:
        jc = OxmlElement("w:jc")
        jc.set(qn("w:val"), align)
        pPr.append(jc)
    if text:
        make_run(p._element, text, cn, EN, size, bold)


def anchor(idx, expect):
    el = CH[idx]
    txt = "".join(n.text or "" for n in el.iter(qn("w:t"))) if el.tag == qn("w:p") else ""
    if expect not in txt:
        raise SystemExit("锚点 %d 不匹配：%r（期望含 %r）" % (idx, txt[:50], expect))
    return el


def drop(idx):
    el = CH[idx]
    el.getparent().remove(el)


def read_text(name):
    return io.open(os.path.join(HERE, name), encoding="utf-8").read().rstrip("\n")


def split_modules(path, markers):
    lines = read_text(path).split("\n")
    starts = []
    for m in markers:
        i = next(i for i, l in enumerate(lines) if m in l)
        while not lines[i].startswith("/*==="):
            i -= 1
        starts.append(i)
    chunks = ["\n".join(lines[:starts[0]]).rstrip("\n")]
    for k, s in enumerate(starts):
        e = starts[k + 1] if k + 1 < len(starts) else len(lines)
        chunks.append("\n".join(lines[s:e]).rstrip("\n"))
    return chunks


# ----------------------------------------------------------------- 1. 表头信息
p1 = CH[1]
for r in list(Paragraph(p1, doc).runs):
    r._element.getparent().remove(r._element)
for tag in ("w:spacing",):
    for old in p1.findall(qn("w:pPr") + "/" + qn(tag)):
        old.getparent().remove(old)
make_run(p1, "年级： 2025级   专业： 计算机科学与技术   学号： 25080900217   姓名： 干林锋",
         cn=HEI, size=12)

# ----------------------------------------------------------------- 2. 清空待填空行
for idx in (26, 27, 28, 30, 31, 32, 48, 49, 50, 51,
            71, 73, 76, 78, 79, 81, 83):
    drop(idx)

# ----------------------------------------------------------------- 3. 源代码分块
M1 = [" * 模块1：随机数组生成", " * 模块5：输出与性能测试（基础部分）",
      " * 模块2：冒泡排序（改进版）", " * 模块3：选择排序",
      " * 模块4：归并排序（分治法", " * 模块5（续）：结果输出与性能测试主流程"]
h1, m1, m5a, m2, m3, m4, m5b = split_modules("exp1_sort.cpp", M1)
M2 = [" * 模块1：输入处理", " * 模块2：基础蛮力法", " * 模块3：改进蛮力法",
      " * 模块4：结果输出与时间统计"]
n0, n1, n2, n3, n4 = split_modules("exp2_chicken.cpp", M2)

# ----------------------------------------------------------------- 题目1：算法原理
c = Cur(anchor(25, "冒泡排序（改进版）："))
c.p("基本原理：冒泡排序属于典型的蛮力法。它反复扫描待排序序列，依次比较相邻的两个元素，"
    "若前者大于后者（逆序）则交换两者位置。这样每完成一趟扫描，当前待排序区间中的最大元素"
    "就会像水中的气泡一样“浮”到区间末尾，有序区长度增加 1。若序列长度为 n，则最多需要 n−1 "
    "趟扫描，每趟扫描的比较次数依次为 n−1、n−2、…、1，总比较次数为 n(n−1)/2。",
    indent_chars=2, align="both")
c.p("改进思路：设置标志位（本程序中为 swapped），若某一趟扫描中“没有发生任何元素交换”，"
    "说明整个序列已经有序，后续趟次不可能再产生交换，因此立即终止算法。这一改进使算法在"
    "处理基本有序或已然有序的序列时性能显著提升。", indent_chars=2, align="both")
c.p("实测验证：n = 100 的随机数组最坏需比较 4 950 次，改进版实际执行 4 797 次；n = 1000 时"
    "最坏 499 500 次、实际 499 004 次；n = 10000 时最坏 49 995 000 次、实际 49 984 989 次，"
    "均少于最坏情况，说明确实有若干趟扫描在序列已有序时提前结束。", indent_chars=2, align="both")
c.table(["分析项", "结论"],
        [["时间复杂度（最坏、平均）", "O(n²)，每趟比较次数呈等差数列，总计 n(n−1)/2 次"],
         ["时间复杂度（最好）", "O(n)，原始序列已有序时，第 1 趟无交换即终止"],
         ["空间复杂度", "O(1)，仅需常数个辅助变量，原地排序"],
         ["稳定性", "稳定，仅当 a[j] > a[j+1] 时才交换，相等元素相对次序不变"],
         ["统计量", "比较次数约 n²/2；移动次数 = 3 × 交换次数"]],
        widths=[4.2, 11.2], caption="表 1-1  冒泡排序（改进版）性能特征分析",
        aligns=["center", "left"])

c = Cur(anchor(29, "选择排序："))
c.p("基本原理：选择排序把数组划分为“已排序区”和“未排序区”，初始时已排序区为空。每一趟"
    "从未排序区中选出最小（或最大）的元素，将其与未排序区的第一个元素交换位置，使已排序区"
    "长度增加 1，n−1 趟之后整个序列有序。", indent_chars=2, align="both")
c.p("特点：选择排序的比较次数与数据的初始排列无关，第 i 趟固定比较 n−1−i 次，总计恒为 "
    "n(n−1)/2 次；但每趟最多只发生 1 次交换，因此元素移动次数很少，仅为 O(n) 量级。这一点在"
    "本实验数据中体现得非常明显：n = 10000 时选择排序的比较次数为 49 995 000 次，移动次数"
    "却只有 29 979 次。", indent_chars=2, align="both")
c.table(["分析项", "结论"],
        [["时间复杂度（最好、最坏、平均）", "均为 O(n²)，比较次数恒为 n(n−1)/2"],
         ["空间复杂度", "O(1)，原地排序"],
         ["稳定性", "不稳定，交换可能破坏相等元素的相对次序"],
         ["统计量特点", "比较次数固定；移动次数 = 3 × 交换次数，仅为 O(n)"]],
        widths=[5.0, 10.4], caption="表 1-2  选择排序性能特征分析",
        aligns=["center", "left"])

c = Cur(anchor(33, "归并排序："))
c.p("基本原理：归并排序是分治法的典型应用，其执行过程可概括为“分解—合并”两个阶段。",
    indent_chars=2, align="both")
c.p("分解：把待排序区间从中间一分为二（mid = left + (right−left)/2），对左右两个子区间分别"
    "递归地排序；当子区间只剩 1 个元素时天然有序，递归结束。", indent_chars=2, align="both")
c.p("合并：把两个已经有序的子数组 a[left..mid] 与 a[mid+1..right] 合并为一个有序数组。做法是"
    "设置两个游标分别指向两段的起始位置，每次比较两个游标所指元素，把较小者放入临时数组，"
    "游标后移；当某一段取完后，把另一段剩余元素依次搬入临时数组；最后把临时数组的结果整体"
    "写回原数组对应区间。合并过程中若取 a[i] <= a[j] 则优先取左段元素，从而保证算法的稳定性。",
    indent_chars=2, align="both")
c.p("复杂度分析：分解过程把区间二分，共 log₂n 层；每层的合并操作需要遍历该层全部 n 个元素，"
    "代价为 O(n)。因此无论数据初始排列如何，总时间复杂度恒为 O(n log n)，这是归并排序相对"
    "两种蛮力排序的根本优势；代价是需要一个与原数组等长的辅助数组，空间复杂度为 O(n)。",
    indent_chars=2, align="both")
c.table(["分析项", "结论"],
        [["时间复杂度（最好、最坏、平均）", "均为 O(n log n)，与数据初始排列无关"],
         ["空间复杂度", "O(n)，需要等长辅助数组存放合并结果"],
         ["稳定性", "稳定，合并时取 a[i] <= a[j] 保证相等元素先后次序不变"],
         ["统计量", "比较次数约 n·log₂n；移动次数约 2n·log₂n（含写回原数组）"]],
        widths=[5.0, 10.4], caption="表 1-3  归并排序性能特征分析",
        aligns=["center", "left"])

# ----------------------------------------------------------------- 题目1：代码
c = Cur(anchor(34, "代码实现步骤"))
c.p("本程序用 C++17 编写，未调用任何标准库排序函数，按实验要求的五个模块组织如下。"
    "各模块代码按顺序拼接后即为完整可编译源文件 exp1_sort.cpp（共 296 行）。",
    indent_chars=2, align="both", after=4)
c.p("程序头部（文件说明、头文件、常量定义与函数声明）", size=ANS, bold=True, cn=HEI, after=2)
c.code(h1)

c = Cur(anchor(35, "模块1：随机数组生成"))
c.code(m1)
c.p("说明：rand() 在 Windows 下 RAND_MAX = 32767，取值只有 32768 个，映射到 [1, 100000] 上"
    "必然出现重复元素，即生成的随机整数允许重复，符合实验要求；种子固定为 20250809 + n，"
    "保证同一规模下每次运行得到完全相同的数组，三种算法共用同一份数据。",
    indent_chars=2, align="both", before=2)

c = Cur(anchor(37, "模块2：冒泡排序（改进版）实现"))
c.code(m2)

c = Cur(anchor(39, "模块3：选择排序实现"))
c.code(m3)

c = Cur(anchor(41, "模块4：归并排序实现"))
c.code(m4)

c = Cur(anchor(43, "模块5：性能测试与结果输出"))
c.code(m5a + "\n\n" + m5b)
c.p("说明：小规模排序单次耗时常常不足 1 微秒，直接测量会被时钟分辨率淹没，因此对同一随机"
    "数组连续排序 repeat 次（n = 100、1000、10000 分别取 500、50、1 次）再除以 repeat 得到"
    "单次平均耗时，每种算法测量 3 次后取平均；比较次数与移动次数只取决于算法与数据，"
    "单独执行一次精确统计。程序开头调用 SetConsoleOutputCP(CP_UTF8) 保证中文输出在控制台"
    "与截图中都不乱码。", indent_chars=2, align="both", before=2)

# ----------------------------------------------------------------- 题目1：测试用例表与截图
t_case = ORIG_T1
conclusions = [
    "归并排序最快（1.33 微秒）；冒泡、选择排序分别是它的 5.0 倍和 6.0 倍，规模小时差距不大",
    "归并排序（26.66 微秒）已明显领先，比冒泡排序快约 30.4 倍、比选择排序快约 28.4 倍",
    "归并排序（333.43 微秒）比冒泡排序快约 186.2 倍、比选择排序快约 276.5 倍，优势急剧扩大",
]
for ri, text in enumerate(conclusions, start=1):
    ref_align = t_case.cell(ri, 1).paragraphs[0].alignment
    fmt_cell(t_case.cell(ri, 2), text, size=11.0, align="both" if ref_align is None else None)

c = Cur(t_case._tbl)
c.p("补充说明：三种规模使用同一随机数生成规则（srand/rand 生成 [1, 100000] 的整数），"
    "每种算法独立执行 3 次取平均值；由于随机数种子固定，同一规模下每次运行得到的数组完全"
    "相同，实验结果可复现，且三种算法面对的数据完全一致，比较是公平有效的。",
    indent_chars=2, align="both", before=6)
c.p("运行截图", size=ANS, bold=True, cn=HEI, before=8, after=2)
c.p("下列截图取自程序在 n = 100、1000、10000 三种规模下的真实运行输出，每张截图均显示了"
    "数据规模、算法名称、排序前后数组片段、3 次运行的比较次数、移动次数与平均执行时间，"
    "以及结果正确性校验。", indent_chars=2, align="both")
c.p("（1）数据规模 n = 100")
c.fig("exp1_n100_1.png", "图 1-1  冒泡排序（改进版）在 n = 100 时的运行结果", 15.5)
c.fig("exp1_n100_2.png", "图 1-2  选择排序在 n = 100 时的运行结果", 15.5)
c.fig("exp1_n100_3.png", "图 1-3  归并排序在 n = 100 时的运行结果", 15.5)
c.p("（2）数据规模 n = 1000")
c.fig("exp1_n1000_1.png", "图 1-4  冒泡排序（改进版）在 n = 1000 时的运行结果", 15.5)
c.fig("exp1_n1000_2.png", "图 1-5  选择排序在 n = 1000 时的运行结果", 15.5)
c.fig("exp1_n1000_3.png", "图 1-6  归并排序在 n = 1000 时的运行结果", 15.5)
c.p("（3）数据规模 n = 10000")
c.fig("exp1_n10000_1.png", "图 1-7  冒泡排序（改进版）在 n = 10000 时的运行结果", 15.5)
c.fig("exp1_n10000_2.png", "图 1-8  选择排序在 n = 10000 时的运行结果", 15.5)
c.fig("exp1_n10000_3.png", "图 1-9  归并排序在 n = 10000 时的运行结果", 15.5)

# ----------------------------------------------------------------- 题目1：性能分析
c = Cur(anchor(47, "性能分析："))
c.table(["数据规模 n", "算法", "比较次数（次）", "移动次数（次）", "平均执行时间（μs）"],
        [["100", "冒泡排序（改进版）", "4,797", "7,119", "6.666"],
         ["100", "选择排序", "4,950", "291", "8.000"],
         ["100", "归并排序", "536", "1,344", "1.333"],
         ["1000", "冒泡排序（改进版）", "499,004", "742,056", "810.229"],
         ["1000", "选择排序", "499,500", "2,982", "756.873"],
         ["1000", "归并排序", "8,691", "19,952", "26.661"],
         ["10000", "冒泡排序（改进版）", "49,984,989", "74,503,941", "62,073.167"],
         ["10000", "选择排序", "49,995,000", "29,979", "92,195.267"],
         ["10000", "归并排序", "120,493", "267,232", "333.433"]],
        widths=[2.2, 3.8, 3.2, 3.2, 3.0],
        caption="表 1-4  三种排序算法在三种数据规模下的平均性能数据", size=9.5, header_size=9.5,
        caption_before=2)
c.fig("chart_time.png", "图 1-10  三种排序算法执行时间随数据规模的变化（双对数坐标）", 15.5)
c.fig("chart_counts.png", "图 1-11  三种排序算法的比较次数与移动次数对比（对数坐标）", 15.5)
c.p("性能分析结论", size=ANS, bold=True, cn=HEI, before=8, after=2)
for t in [
    "（1）三种算法耗时随规模的增长速度完全不同。规模由 100 增至 10000（扩大 100 倍）时，冒泡排序耗时由 6.67 微秒增至 62 073 微秒，选择排序由 8.00 微秒增至 92 195 微秒，增长幅度都在 7 000 倍以上，符合 O(n²) 的平方级增长规律；而归并排序由 1.33 微秒增至 333 微秒，只增长约 250 倍，与 O(n log n) 的理论预期一致。",
    "（2）数据规模越大，归并排序的优势越明显。n = 100 时归并排序（1.33 微秒）只是略快于冒泡排序（6.67 微秒），三种算法处于同一数量级；n = 1000 时归并排序已比冒泡排序快约 30.4 倍；到 n = 10000 时，归并排序（333 微秒）比冒泡排序快约 186.2 倍、比选择排序快约 276.5 倍，说明规模增大后 O(n log n) 与 O(n²) 之间的差距才充分体现。",
    "（3）比较次数与移动次数由算法设计决定，与运行环境无关。n = 10000 时，冒泡排序比较 49 984 989 次、选择排序比较 49 995 000 次，都接近 n(n−1)/2 = 49 995 000 次的理论值，而归并排序只需 120 493 次；移动次数方面选择排序最少（29 979 次，每趟最多交换一次），冒泡排序最多（74 503 941 次），归并排序居中（267 232 次）。",
    "（4）改进版冒泡排序的提前终止确实有效，但对随机数据收益有限：相对最坏情况的比较次数减少量分别为 3.1%（n = 100）、0.10%（n = 1000）和 0.02%（n = 10000），呈下降趋势——随机数据整体无序，规模越大越难出现“整趟无交换”的情形。",
]:
    c.p(t, indent_chars=2, align="both")
c.p("实验结论", size=ANS, bold=True, cn=HEI, before=8, after=2)
for t in [
    "（1）三种算法都能正确完成排序，程序内置的“非递减有序”校验在全部 9 组测试中全部通过。",
    "（2）冒泡排序与选择排序的时间复杂度为 O(n²)，n = 10000 时耗时分别约为 62 073 微秒和 92 195 微秒；归并排序的分治策略把复杂度降到 O(n log n)，耗时仅 333 微秒，比冒泡排序快约 186.2 倍、比选择排序快约 276.5 倍，且规模越大优势越明显。",
    "（3）比较次数与移动次数由算法设计决定：选择排序比较次数固定但移动次数最少，冒泡排序移动次数最多，归并排序两项指标都远小于两种蛮力排序。",
    "（4）改进版冒泡排序的提前终止在近似有序的数据上能明显减少比较次数，但对完全随机的大规模数据改善有限。",
    "（5）实验表明，通过改进算法设计降低时间复杂度，是提升程序性能最有效的手段。",
]:
    c.p(t, indent_chars=2, align="both")

# ----------------------------------------------------------------- 题目2：问题分析
c = Cur(anchor(70, "基础蛮力法："))
c.p("设计思路：直接枚举公鸡数 a 和母鸡数 b 的所有可能取值，利用 a + b + c = n 直接推出小鸡数 "
    "c = n − a − b，再验证约束条件是否全部满足。由于 a 与 b 的枚举范围都是 [0, n]，各自有 n+1 "
    "种取值，因此循环体恰好执行 (n+1)² = n² + 2n + 1 次，与具体数据无关。",
    indent_chars=2, align="both")
c.p("约束验证：c ≥ 0；c % 3 == 0（小鸡必须 3 只一组）；5a + 3b + c/3 == n。为避免整数除法带来"
    "的误差，程序中把该式等价改写为 15a + 9b + c == 3n 进行判断。", indent_chars=2, align="both")
c.p("时间复杂度：O(n²)（双重循环）；空间复杂度：O(k)，k 为解的组数，用于数组存储多组解。",
    indent_chars=2, align="both")

c = Cur(anchor(72, "改进蛮力法："))
c.p("改进的核心是“用约束条件化简枚举维度”，通过代数消元把一个变量用另一个变量表示出来，"
    "从而把双重循环降为单重循环。推导过程如下：", indent_chars=2, align="both")
for f in ["由  a + b + c = n          ……（1）",
          "    5a + 3b + c/3 = n      ……（2）",
          "把 (1) 式乘以 3：3a + 3b + 3c = 3n      ……（3）",
          "把 (2) 式乘以 3：15a + 9b + c = 3n      ……（4）",
          "(4) − (3) 得：12a + 6b − 2c = 0，即 c = 6a + 3b      ……（5）",
          "把 (5) 代入 (1)：a + b + 6a + 3b = n，即 7a + 4b = n，于是 b = (n − 7a) / 4      ……（6）",
          "再由 c = n − a − b 即可算出小鸡数。可见只需枚举一个变量 a，b 与 c 都能直接算出。"]:
    c.p(f, indent_chars=2, align="both")
c.p("枚举范围优化：由 b = (n − 7a)/4 ≥ 0 可得 a ≤ n/7，因此 a 只需在 [0, n/7] 内枚举，循环体"
    "执行次数由 (n+1)² 次降到约 n/7 + 1 次。", indent_chars=2, align="both")
c.p("时间复杂度：由 O(n²) 降为 O(n)，降低了一个数量级；空间复杂度仍为 O(k)。程序用数组存储"
    "多组解，未使用全局变量，也未使用结构体，满足实验的编码规范要求。", indent_chars=2, align="both")

# ----------------------------------------------------------------- 题目2：代码
c = Cur(anchor(74, "代码实现步骤"))
c.p("本程序用 C++17 编写，按实验要求的四个模块组织如下，各模块拼接后即为完整可编译源文件 "
    "exp2_chicken.cpp（共 222 行）。", indent_chars=2, align="both", after=4)
c.p("程序头部（文件说明、头文件、常量定义）", size=ANS, bold=True, cn=HEI, after=2)
c.code(n0)

c = Cur(anchor(75, "模块1：输入处理"))
c.code(n1)

c = Cur(anchor(77, "模块2：基础蛮力法实现"))
c.code(n2)

c = Cur(anchor(80, "模块3：改进蛮力法实现"))
c.code(n3)

c = Cur(anchor(82, "模块4：结果输出与时间统计"))
c.code(n4)
c.p("说明：两种算法单次执行时间都远小于 1 微秒（n 较小时尤其明显），因此重复执行足够多次使"
    "总耗时达到毫秒量级后再取平均；基础蛮力法耗时为 O(n²)，其重复次数取 2×10⁷/n²，改进蛮力法"
    "取固定值 10⁶。程序最后逐组比对两种算法求得的解集是否完全一致，用于验证约束化简的正确性。",
    indent_chars=2, align="both", before=2)

# ----------------------------------------------------------------- 题目2：测试用例表与截图
t_case2 = ORIG_T2
fill2 = [["1", "961", "5"], ["4", "10,201", "15"], ["36", "1,002,001", "143"]]
for ri, vals in enumerate(fill2, start=1):
    for k, v in enumerate(vals):
        ref_align = t_case2.cell(ri, 1).paragraphs[0].alignment
        fmt_cell(t_case2.cell(ri, 2 + k), v, size=12.0,
                 align=None if ref_align is not None else "center")

c = Cur(t_case2._tbl)
c.p("注：任务书中预估 n = 30 时有 2 组解，由约束 7a + 4b = 30 可知其非负整数解只有 a = 2、"
    "b = 4、c = 24 这一组，程序运行结果与理论推导完全一致，故实际为 1 组解。n = 100 时求得 4 组解："
    "(0, 25, 75)、(4, 18, 78)、(8, 11, 81)、(12, 4, 84)，与经典百鸡问题的预期结果完全一致；"
    "改进蛮力法在三种规模下求得的解集与基础蛮力法完全相同，验证了约束化简推导的正确性。",
    indent_chars=2, align="both", before=6)
c.p("运行截图", size=ANS, bold=True, cn=HEI, before=8, after=2)
c.p("下列截图为程序在三种测试用例下的真实运行输出，均显示了输入 n、算法名称、求得的解、"
    "循环体执行次数与执行时间。", indent_chars=2, align="both")
c.p("（1）测试用例 n = 30")
c.fig("exp2_n30_basic.png", "图 2-1  基础蛮力法求解 n = 30 的结果", 11.0)
c.fig("exp2_n30_impr.png", "图 2-2  改进蛮力法求解 n = 30 的结果", 11.0)
c.p("（2）测试用例 n = 100")
c.fig("exp2_n100_basic.png", "图 2-3  基础蛮力法求解 n = 100 的结果", 11.0)
c.fig("exp2_n100_impr.png", "图 2-4  改进蛮力法求解 n = 100 的结果", 11.0)
c.p("（3）测试用例 n = 1000")
c.fig("exp2_n1000_basic.png", "图 2-5  基础蛮力法求解 n = 1000 的结果", 11.0)
c.fig("exp2_n1000_impr.png", "图 2-6  改进蛮力法求解 n = 1000 的结果", 11.0)

# ----------------------------------------------------------------- 题目2：优化效果分析
c = Cur(anchor(86, "优化效果分析："))
c.table(["n", "解数", "基础版循环次数", "改进版循环次数", "循环次数降低",
         "基础版耗时(μs)", "改进版耗时(μs)", "耗时降低"],
        [["30", "1", "961", "5", "192.2 倍", "0.788", "0.003", "262.7 倍"],
         ["100", "4", "10,201", "15", "680.1 倍", "6.756", "0.008", "844.3 倍"],
         ["1000", "36", "1,002,001", "143", "7007.0 倍", "550.015", "0.101", "5471.1 倍"]],
        widths=[1.1, 1.1, 2.3, 2.3, 2.1, 2.2, 2.2, 2.1],
        caption="表 2-1  基础蛮力法与改进蛮力法性能对比", size=9.0, header_size=9.0,
        caption_before=2)
c.fig("chart_exp2.png", "图 2-7  两种算法循环体执行次数与执行时间对比（对数坐标）", 15.5)
c.p("优化效果分析", size=ANS, bold=True, cn=HEI, before=8, after=2)
for t in [
    "（1）循环次数大幅减少。n = 30 时循环次数由 961 次降到 5 次，n = 100 时由 10 201 次降到 15 次，n = 1000 时由 1 002 001 次降到 143 次，分别降低 192.2 倍、680.1 倍和 7007.0 倍。这与理论分析一致：基础版循环 (n+1)² 次，改进版循环 n/7 + 1 次，规模越大降低越多。",
    "（2）执行时间也明显下降。n = 1000 时基础蛮力法单次耗时 550.015 微秒，改进蛮力法只需 0.101 微秒，降低约 5471.1 倍；n = 30 时两者耗时分别为 0.788 微秒和 0.003 微秒。规模越大，“约束条件化简”的效果越突出。",
    "（3）改进算法结果正确。三种测试用例下，改进蛮力法与基础蛮力法求得的解组数、每组解的数值完全一致（程序中逐组比对校验），说明消元推导和枚举范围 a ≤ n/7 都是正确的，没有遗漏合法解。",
]:
    c.p(t, indent_chars=2, align="both")
c.p("实验结论", size=ANS, bold=True, cn=HEI, before=8, after=2)
for t in [
    "（1）基础蛮力法“枚举所有组合 + 验证约束”的思路直观可靠，但双重循环使时间复杂度为 O(n²)，n = 1000 时循环次数高达 1 002 001 次，执行时间 550 微秒。",
    "（2）改进蛮力法通过消元把三个未知量化为一个枚举变量，并把枚举范围压缩到 [0, n/7]，时间复杂度降为 O(n)，循环次数降到 n/7 + 1 量级。",
    "（3）实测数据显示，n = 1000 时改进算法循环次数降低 7007 倍、执行时间降低 5471 倍，且两种算法解集完全一致，说明“利用约束条件减少枚举量”能在保证正确性的同时大幅提升效率。",
    "（4）优化效果随规模增大而增强，说明在枚举类问题中充分利用约束条件缩小搜索空间，是最直接有效的优化途径。",
]:
    c.p(t, indent_chars=2, align="both")

doc.save(OUT)
print("saved:", OUT)
