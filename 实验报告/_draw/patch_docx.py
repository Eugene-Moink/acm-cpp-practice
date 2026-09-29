# -*- coding: utf-8 -*-
"""把重绘的流程图写回 三级项目-学号-姓名.docx"""
import os, re, shutil, zipfile

BASE = r'C:\Users\墨轩\acm-cpp-practice\实验报告'
DOCX = os.path.join(BASE, '三级项目-学号-姓名.docx')
BACKUP = os.path.join(BASE, '三级项目-学号-姓名.备份(原图).docx')
FIG = {k: os.path.join(BASE, v) for k, v in {
    'legend': '业务流程图-基本符号.png',
    'bfd1': '业务流程图-一层图-招聘管理.png',
    'bfd2': '业务流程图-二层图-薪酬核算与发放.png',
}.items()}

R_NS = 'http://schemas.openxmlformats.org/officeDocument/2006/relationships'

if not os.path.exists(BACKUP):
    shutil.copy2(DOCX, BACKUP)
    print('backup ->', BACKUP)

zin = zipfile.ZipFile(DOCX)
parts = {n: zin.read(n) for n in zin.namelist()}
zin.close()

doc = parts['word/document.xml'].decode('utf-8')
rels = parts['word/_rels/document.xml.rels'].decode('utf-8')

# ------------------------------------------------------------------
# 1. 3.2.2 段落文字：去掉“泳道”说法，改为四项业务功能
# ------------------------------------------------------------------
old = ('图 4 是薪酬核算与发放业务流程的二层图，采用泳道的形式，把业务活动按承担者划分'
       '为“员工/业务部门”、“人力资源部·薪酬专员”、“财务部”、“银行/员工”四条泳道，'
       '以表示各参与方在同一流程中的职责分工与协作关系。')
new = ('图 4 是薪酬核算与发放业务流程的二层图，按业务处理步骤把该流程进一步分解为'
       '“1 考勤数据汇总与审核”“2 工资计算与代扣”“3 工资表复核与审批”'
       '“4 工资发放与台账归档”四个业务功能，各业务功能的承担者用客观实体/人符号'
       '和带箭头的虚线表示，以体现各参与方在同一流程中的职责分工与协作关系。')
assert doc.count(old) == 1, doc.count(old)
doc = doc.replace(old, new)

old2 = '最后薪酬专员将工资数据归档形成薪资台账。'
assert doc.count(old2) == 1, doc.count(old2)
doc = doc.replace(old2, '最后薪酬专员将工资数据归档形成薪资发放台账。')

# ------------------------------------------------------------------
# 2. 图号顺延：图 3 → 图 4 … 图 15 → 图 16
# ------------------------------------------------------------------
def bump(m):
    n = int(m.group(1))
    return '图 %d' % (n + 1) if 3 <= n <= 15 else m.group(0)

doc = re.sub(r'图 (\d+)', bump, doc)
print('图号顺延完成，现引用：', sorted(set(re.findall(r'图 \d+', doc)), key=lambda s: int(s[2:])))

# ------------------------------------------------------------------
# 3. 在 3.2 节正文之后插入“基本符号”说明 + 图例 + 图题
# ------------------------------------------------------------------
anchor = '<w:p w14:paraId="2E32035A"><w:pPr><w:pStyle w:val="5"/>'
assert doc.count(anchor) == 1

LEG_W, LEG_H = 5040000, 2469600          # 14.0 cm × 6.86 cm
body = ('业务流程图采用统一的图形符号绘制，本报告中的业务流程图均按下述六种基本符号绘制：'
        '业务功能描述用上部带一条横线的矩形表示，横线上方填写在整个系统中唯一的业务功能标识；'
        '各类单证、报表用下部为波浪线的矩形表示；数据存储或文档用右侧开口的矩形表示；'
        '客观实体/人用圆形表示；信息的流动及方向用带箭头的实线表示；某项业务由谁完成，'
        '则在客观实体/人与业务功能描述两个符号之间用带箭头的虚线表示，如图 3 所示。')
para_txt = (
    '<w:p w14:paraId="7A100001"><w:pPr><w:kinsoku/><w:autoSpaceDE/><w:autoSpaceDN/>'
    '<w:spacing w:before="0" w:after="0" w:line="300" w:lineRule="auto"/>'
    '<w:ind w:firstLine="480" w:firstLineChars="200"/><w:jc w:val="both"/></w:pPr>'
    '<w:r><w:rPr><w:rFonts w:ascii="Times New Roman" w:hAnsi="Times New Roman" w:eastAsia="宋体"/>'
    '<w:b w:val="0"/><w:i w:val="0"/><w:sz w:val="24"/></w:rPr>'
    '<w:t>%s</w:t></w:r></w:p>' % body)
para_img = (
    '<w:p w14:paraId="7A100002"><w:pPr><w:kinsoku/><w:autoSpaceDE/><w:autoSpaceDN/>'
    '<w:spacing w:before="120" w:after="40" w:line="240" w:lineRule="auto"/>'
    '<w:jc w:val="center"/></w:pPr><w:r><w:drawing>'
    '<wp:inline distT="0" distB="0" distL="114300" distR="114300">'
    '<wp:extent cx="%d" cy="%d"/>'
    '<wp:effectExtent l="0" t="0" r="8255" b="8255"/>'
    '<wp:docPr id="17" name="Picture 17"/><wp:cNvGraphicFramePr>'
    '<a:graphicFrameLocks xmlns:a="http://schemas.openxmlformats.org/drawingml/2006/main" noChangeAspect="1"/>'
    '</wp:cNvGraphicFramePr><a:graphic xmlns:a="http://schemas.openxmlformats.org/drawingml/2006/main">'
    '<a:graphicData uri="http://schemas.openxmlformats.org/drawingml/2006/picture">'
    '<pic:pic xmlns:pic="http://schemas.openxmlformats.org/drawingml/2006/picture">'
    '<pic:nvPicPr><pic:cNvPr id="17" name="Picture 17"/><pic:cNvPicPr><a:picLocks noChangeAspect="1"/>'
    '</pic:cNvPicPr></pic:nvPicPr><pic:blipFill><a:blip r:embed="rId100"/>'
    '<a:stretch><a:fillRect/></a:stretch></pic:blipFill><pic:spPr><a:xfrm><a:off x="0" y="0"/>'
    '<a:ext cx="%d" cy="%d"/></a:xfrm><a:prstGeom prst="rect"><a:avLst/></a:prstGeom>'
    '</pic:spPr></pic:pic></a:graphicData></a:graphic></wp:inline></w:drawing></w:r></w:p>'
    % (LEG_W, LEG_H, LEG_W, LEG_H))
para_cap = (
    '<w:p w14:paraId="7A100003"><w:pPr><w:kinsoku/><w:autoSpaceDE/><w:autoSpaceDN/>'
    '<w:spacing w:before="0" w:after="200" w:line="240" w:lineRule="auto"/>'
    '<w:jc w:val="center"/></w:pPr><w:r><w:rPr>'
    '<w:rFonts w:ascii="Times New Roman" w:hAnsi="Times New Roman" w:eastAsia="宋体"/>'
    '<w:b w:val="0"/><w:i w:val="0"/><w:sz w:val="21"/></w:rPr>'
    '<w:t>图 3\u3000业务流程图的基本符号</w:t></w:r></w:p>')

doc = doc.replace(anchor, para_txt + para_img + para_cap + anchor)

# ------------------------------------------------------------------
# 4. 修正两张重绘图在文档中的显示尺寸（保持 15.5 cm 宽，高度按新比例）
# ------------------------------------------------------------------
def fit(rid, png):
    global doc
    from PIL import Image
    w, h = Image.open(png).size
    ratio = w / h
    m = re.search(r'<w:p [^>]*>(?:(?!</w:p>).)*?r:embed="%s".*?</w:p>' % rid, doc, re.S)
    assert m, rid
    p = m.group(0)
    ext = re.search(r'<wp:extent cx="(\d+)" cy="(\d+)"/>', p)
    cx = int(ext.group(1))
    cy = round(cx / ratio)
    p2 = p.replace(ext.group(0), '<wp:extent cx="%d" cy="%d"/>' % (cx, cy))
    ae = re.search(r'<a:ext cx="(\d+)" cy="(\d+)"/>', p2)
    cx2 = int(ae.group(1))
    cy2 = round(cx2 / ratio)
    p2 = p2.replace(ae.group(0), '<a:ext cx="%d" cy="%d"/>' % (cx2, cy2))
    doc = doc.replace(p, p2)
    print('%s -> %d x %d EMU (%.2f x %.2f cm, ratio %.4f)'
          % (rid, cx, cy, cx / 360000, cy / 360000, ratio))


fit('rId8', FIG['bfd1'])
fit('rId9', FIG['bfd2'])

# ------------------------------------------------------------------
# 5. 关系 + 媒体
# ------------------------------------------------------------------
assert 'rId100' not in rels
rels = rels.replace(
    '</Relationships>',
    '<Relationship Id="rId100" Type="%s/image" Target="media/image17.png"/></Relationships>' % R_NS)

parts['word/document.xml'] = doc.encode('utf-8')
parts['word/_rels/document.xml.rels'] = rels.encode('utf-8')
parts['word/media/image3.png'] = open(FIG['bfd1'], 'rb').read()
parts['word/media/image4.png'] = open(FIG['bfd2'], 'rb').read()
parts['word/media/image17.png'] = open(FIG['legend'], 'rb').read()

tmp = DOCX + '.new'
zout = zipfile.ZipFile(tmp, 'w', zipfile.ZIP_DEFLATED)
for name, data in parts.items():
    zout.writestr(name, data)
zout.close()
os.replace(tmp, DOCX)
print('written ->', DOCX)
