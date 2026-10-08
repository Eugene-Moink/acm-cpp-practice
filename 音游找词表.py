import random
import string
import unicodedata
import re

# ========== 默认配置 ==========
DEFAULT_WIDTH = 60
DEFAULT_HEIGHT = 60
MAX_ATTEMPTS = 2000
FILL_CHARS = string.ascii_uppercase + string.digits
SPACED = True
SHOW_ANSWERS = True

# ========== 分类权重配置 ==========
CATEGORY_WEIGHTS = {
    "Arcaea": 4,
    "maimai": 4,
    "Phigros": 1,
    "Muse Dash": 1,
    "CHUNITHM": 1,
}

# ========== 歌名词库（字典格式，按分类） ==========
WORD_LIST = {
    # ============================================================
    # ===== Arcaea =====
    # ============================================================
    "Arcaea": [
        "DREAD AREA", "Cataclysm Cry", "DIE IN", "Riot in the System",
        "Balor", "un", "Riven Pilgrimage", "World Extend 4",
        "Xterfusion", "Lament Rain", "Designant.", "AlterGate",
        "Dematerialized", "INCARNATOR₀₀", "MARENYX", "INFINITE DIMENSION",
        "Code: Oblivion", "zephyrlasting", "⊥⊬", "Château de cartes",
        "Grievous Lady", "Pentiment", "Tempestissimo", "Testify",
        "World Ender", "Incyde", "Arcana Eden", "Infinite Strife",
        "Fracture Ray", "Ether Strike", "Halcyon", "Pragmatism",
        "Sheriruth", "GLORY ROAD", "Saikyo", "Nhelv",
        "Don't Die", "Empire of Winter", "Galactic Love", "lastendconductor",
        "STARGATE EXTREAM", "Distorted Fate", "Floating World",
        "Monochrome Princess", "Crimson Quartz", "MINIRAE",
        "Abstruse Dilemma", "Cytokinesis", "Lethaeus", "Alter Ego",
        "Aleph-0", "Chronostasis", "PRIMITIVE LIGHTS",
        "Lost Civilization", "cry of viyella", "Sayonara Hatsukoi",
        "Vexaria", "Essence of Twilight", "Qualia", "Lumia",
        "Dement", "Dandelion", "Anokumene", "Infinity Heaven",
        "Party Vinyl", "Flashback", "Flyburg", "Nirvluce",
        "Paradise", "Brand New World", "Data Error", "Cross Soul",
        "Your Voice So", "Kanagawa", "Moonlight of Sandcastle",
        "Reconstruction", "Rise", "Goodtek", "Lucifer",
        "Fairytale", "Heard It Said", "Babaroque", "Memoryfactory",
        "Snow White", "Relentless", "Shades of Light", "Viyella",
        "MEGALOVANIA (Camellia Remix)", "Spider Dance", "Spear of Justice",
        "ASGORE", "Gimme Caramel Popcorn", "Eternity Break",
        "Wake in Hour", "MIRROR - kamome sano remix",
    ],

    # ============================================================
    # ===== maimai =====
    # ============================================================
    "maimai": [
        "INTJINTPENTJENTPINFJENFJINFPENFP ISTJISFJESTJESFJESTPISTPISFPESFP",
        "純情アルメリア", "運命線上のアリア", "デンデラパーティーナイト",
        "Absolute Queen", "Intergalactic Bound", "LEMON MELON COOKIE",
        "3rd Avenue", "ミルクミルクミルク", "BOW AND ARROW",
        "Nine Point Eight", "When The Time Comes", "Antikythera [Vocal Version]",
        "光線歌", "電脳眠眠猫", "相性×優勝ドロップス", "Idios",
        "ツムギボシ", "トノサマビーム", "enchanted wanderer",
        "Comet Panto Men!", "アンバークロニクル", "リフヴェイン",
        "宵の鳥", "Kairos", "隠密あんみつDX", "地球",
        "Churros Parlor", "超熊猫的周遊記", "ヱデン", "にゃーにゃー冒険譚",
        "VeRForTe αRtE:VEiN", "ここからはじまるプロローグ。",
        "モ°ルモ°ル", "VERTeX", "ホシシズク", "HECATONCHEIR",
        "Rising on the horizon", "World's end loneliness",
        "壱雫空", "アイドル", "過去を喰らう", "Freak Out Hr.",
        "強風オールバック", "寝起きヤシの木", "ラビットホール",
        "はいよろこんで", "ビビデバ", "シカ色デイズ",
        "きゅびずむ", "ゆりかご", "月光", "メズマライザー",
        "ももいろの鍵", "のだ", "大漠波新", "T氏の話を信じるな",
        "超ナイト・オブ・ナイツ", "浮世絵横丁", "AiAe", "KNØCK ØUT!!",
        "Oshama Scramble!", "Break The Speakers", "QZKago Requiem", "SPELL MAGIC",
        "galaxias!", "Get Off of My Way", "Love or Lies", "jelly",
        "come again", "CAN'T GET BACK", "Love & Joy", "Garden",
        "Future", "Arrival of Tears", "Stand Up!!!!",
        "The Other self", "STAIRWAY TO GENERATION",
        "Tidal Wave", "イーヴィルガール", "Supersonic Generation",
        "FREEDOM DiVE (tpz Overcute Remix)", "PANDORA PARADOXXX",
        "the EmpErroR", "Alea jacta est", "Idoratrize World", "Synthesis.",
        "NIGHT OF FIRE", "Love You", "Myosotis",
        "ZEUS", "美しく燃える森", "fantastic dreamer", "Rodeo Machine",
        "バベル", "ゆけむり魂温泉 II", "MORNINGLOOM", "病み垢ステロイド",
        "オーバーライド", "夢現妄想世界", "人間が大好きなこわれた妖怪の唄",
        "最愛人生ランナー", "ウィーアーピコピコハンマーズ", "トレジャーガーデン",
        "電光刹歌", "バグ", "熱異常", "1000年生きてる", "IMWANOKIWA",
        "ヒアソビ", "黒百合", "ViRTUS", "Aegleseeker", "Baddest",
        "World Vanquisher", "Lost Desire", "Upshift", "AMAZING MIGHTYYYY!!!!",
        "Beat Opera op.1", "Garakuta Doll Play", "Jack-the-Ripper◆",
        "SPILL OVER COLORS", "三妖精SAY YA!!!", "ありふれたせかいせいふく",
        "エゴロック", "Caliburne ～Story of the Legendary sword～", "oboro",
        "Straight into the lights", "crazy (about you)", "萌萌点火Fire",
        "催眠术", "オパオパ", "Space Harrier", "Mushup",
    ],

    # ============================================================
    # ===== Phigros =====
    # ============================================================
    "Phigros": [
        "雪降り", "AbsoluTe disoRdeR", "NWAD", "地狱之城",
        "Re_Nascence (Psystyle Ver.)", "After Dawn", "INFiNiTE ENERZY -Overdoze-",
        "Khalid", "Quantum Hyperspace", "PANIC PARADISE",
        "Re:End of a Dream", "Spotlight", "NightTheater", "Ramification",
        "Der Richter", "ATHAZA", "Implexrough", "Evanescent",
        "About The Universe", "TECHNOPOLIS 2085", "Break Over",
        "El Condor Pasa Phigros Edit", "Double Agent", "GOLD TOWN",
        "REANIMATE", "Quo Vadis", "Der Schneid", "Cryogenic",
        "PLEASE", "幻影鬼魅", "法官", "终梦", "BQ", "白复生",
        "今天不是明天", "反命题", "is", "月咏", "Cuvism3", "君往何处",
        "暗夜苏醒", "心之记忆", "幽世桔梗", "千紫万红", "明镜烈火",
        "Igallta", "Goodbounce", "Freedom Dive", "Spasmodic", "Stasis",
        "Energy Synergy Matrix", "Junxion between life and death", "Another Me",
        "Aphasia", "Bitterblossom", "Protoflicker", "You are the Miserable",
        "Demonkin", "Forged Reigns", "NO ONE YES MAN", "Leave All Behind",
        "Class Memories", "Sultan Rage", "Ad astra per aspera", "Retribution",
        "Bounded Quietude", "RESSiSTANCE", "Non-Melodic Ragez (MUG Edit)",
        "GOODRAGE", "Cthugha", "Fractured Angel", "Pont des souvenirs", "PRAW",
        "Sparkle New Life", "Glaciaxion", "-Arkhei-", "Clock Paradox",
        "Rainy Heart", "Snow Desert", "Dlyrotz",
        "artificial existence", "xenolith", "bloom",
        "Freaky Undulations ~Noble Knights of Tune~", "Eradication Catastrophe",
        "Credits", "Engine x Start!! (melody mix)",
    ],

    # ============================================================
    # ===== Muse Dash =====
    # ============================================================
    "Muse Dash": [
        "Death by Glamour", "MEGALOVANIA", "Last Goodbye", "BIG SHOT",
        "Attack of the Killer Queen", "雨露霜雪", "World's end loneliness",
        "殿ッ！？ご乱心！", "電波的妄想美少女Q", "待宵夜虫",
        "INTERNET YAMERO", "INTERNET OVERDOSE", "Breaking Dawn",
        "Lights of Muse", "Magical Wonderland", "Wonderful Pain",
        "Echo over you...", "Heart Message", "Frost Land",
        "Pancake is Love", "Evolution", "Night Wander", "Gloomy Flash",
        "Queen Aluett", "Final Flash Flight", "Everything's Alright",
        "Record one's Dream", "Stra Stella", "Heart-Pounding Flight",
        "時光塗鴉", "海豚與廣播 feat.Uranyan", "雪の雫・雨の音",
        "Best One feat.tooko", "糖果色戀愛学", "ドーナドーナのうた",
        "Spring Carnival", "Iyaiya", "Magical Wonderland (More colorful mix)",
        "夢追う者よ feat. をとは", "Chariot", "GASHATT",
        "Medicine of Sing", "無人区-Vacuum Track#ADD8E6",
        "Future Dive", "World Vanquisher", "The Whole Rest",
        "mew mew magical summer", "ЯUBY:LINTe", "雪降り、メリクリ (MD edit)",
        "嗅炸弹的博美犬", "轮滑迪斯科震颤", "玫瑰花园",
        "EMOMOMO", "赫拉克勒斯", "Bad Apple!! feat. Nomico",
        "色は匂へど散りぬるを", "チルノのパーフェクトさんすう教室",
        "緋色月下、狂咲ノ絶", "花月夜", "無意識レクイエム",
        "ONOMATO Pairing!!!", "with U",
    ],

    # ============================================================
    # ===== CHUNITHM =====
    # ============================================================
    "CHUNITHM": [
        "Verse X", "DOMiNUS_GRAiL", "Ribbon",
        "幕を下ろそう、パレードへ", "空気力学少女と少年の詩",
        "こころに響く恋ほたる", "さくらんぼキッス～爆発だも～ん～",
        "Re:Still", "Bling-Bang-Bang-Born", "愛♡スクリ～ム！",
        "英雄の証", "TAIDADA", "ぎゅむ！", "モエチャッカファイア", "唱",
        "ラヴィ", "モミアゲヲシャカアゲヲ", "テトリス",
        "最終鬼畜妹フランドール・S (Chroma Remix)", "Aoharu",
        "Unwelcome School", "彩りキャンバス", "8OROCHI",
        "Megameteor", "Ghost Dance", "理想 ～ Cloudland",
        "にゃんきー魂", "PSYQUI feat.Such",
        "デビルじゃないもん", "あいのうた", "電光刹歌",
        "Trackless wilderness", "Rendezvous", "Another Day",
        "Beyond the Horizon", "Can't it be true", "Credits",
        "Gate of Doom", "popcorn", "Xevel", "Last Kingdom",
        "A Man In The Mirror", "The Darkness of Valhalla",
        "すろぉもぉしょん", "ぼくらの16bit戦争", "ユクエシレズ",
        "愛迷エレジー", "ストリーミングハート", "天ノ弱",
        "一触即発☆禅ガール", "六兆年と一夜物語", "ジングルベル",
        "鳥の詩", "Face of Fact", "Paradisus-Paradoxum", "Vampire",
        "Clover Heart's", "Our Fighting", "タイガーランペイジ",
        "セツナトリップ", "神曲", "ベノム", "ただ君に晴れ",
        "いろは唄", "星屑ユートピア", "Mr. Wonderland",
        "恋愛裁判", "夜咄ディセイブ", "如月アテンション",
        "チルドレンレコード", "カミサマネジマキ",
        "アスノヨゾラ哨戒班", "ウミユリ海底譚", "Hand in Hand",
        "初音ミクの消失", "ロミオとシンデレラ", "深海少女",
        "からくりピエロ", "シジョウノコエ VOCALO ver.",
        "アウターサイエンス", "リモコン", "ラクガキスト",
        "アカツキアライヴァル", "エンヴィキャットウォーク",
        "インビジブル",
    ],
}

# ========== 工具函数 ==========
def normalize_word(s: str) -> str:
    """去掉括号及其内容、空白字符，转大写"""
    # 匹配圆括号、方括号、花括号、中文括号等，并删除括号及其中内容
    s = re.sub(r'[\(\（\[\【\{].*?[\)\）\]\】\}]', '', s)
    return ''.join(s.split()).upper()

def char_width(ch: str) -> int:
    if unicodedata.east_asian_width(ch) in ('W', 'F'):
        return 2
    return 1

# ========== 分层加权采样（按分类权重） ==========
def weighted_sample_by_category(categories, category_weights, num, top_ratio=0.4, hot_weight=3):
    selected = []
    seen = set()

    cats = list(categories.keys())
    weights = [category_weights.get(c, 1) for c in cats]
    total_w = sum(weights)

    raw_counts = [num * w / total_w for w in weights]
    counts = [int(c) for c in raw_counts]
    remainders = [raw_counts[i] - counts[i] for i in range(len(cats))]

    while sum(counts) < num:
        idx = remainders.index(max(remainders))
        counts[idx] += 1
        remainders[idx] = -1

    for cat, count in zip(cats, counts):
        cat_words = categories[cat]
        if not cat_words:
            continue
        hot_count = max(1, int(len(cat_words) * top_ratio))
        hot_pool = cat_words[:hot_count]
        cold_pool = cat_words[hot_count:]

        pool = hot_pool + cold_pool
        wts = [hot_weight] * len(hot_pool) + [1] * len(cold_pool)
        weighted_pool = []
        for w, wt in zip(pool, wts):
            weighted_pool.extend([w] * wt)

        picked = 0
        attempts = 0
        while picked < count and weighted_pool and attempts < len(weighted_pool) * 3:
            pick = random.choice(weighted_pool)
            if pick not in seen:
                selected.append(pick)
                seen.add(pick)
                picked += 1
            attempts += 1
            weighted_pool = [x for x in weighted_pool if x != pick]

        if picked < count:
            remaining = [w for w in pool if w not in seen]
            random.shuffle(remaining)
            for w in remaining[:count - picked]:
                selected.append(w)
                seen.add(w)

    if len(selected) < num:
        all_remaining = []
        for cat in cats:
            all_remaining.extend([w for w in categories[cat] if w not in seen])
        random.shuffle(all_remaining)
        selected.extend(all_remaining[:num - len(selected)])

    return selected[:num]

# ========== 词网格生成器 ==========
class WordSearchGenerator:
    DIRECTIONS = [
        (1, 0), (-1, 0), (0, 1), (0, -1),
        (1, 1), (1, -1), (-1, 1), (-1, -1),
    ]
    DIR_NAMES = {
        (1, 0): "→", (-1, 0): "←", (0, 1): "↓", (0, -1): "↑",
        (1, 1): "↘", (1, -1): "↙", (-1, 1): "↗", (-1, -1): "↖",
    }

    def __init__(self, width, height, words, seed=None):
        self.width = width
        self.height = height
        self.words = sorted(
            {normalize_word(w) for w in words if normalize_word(w)},
            key=len, reverse=True
        )
        self.rng = random.Random(seed)
        self.grid = [['' for _ in range(width)] for _ in range(height)]
        self.placements = []
        self.unplaced = []

    def can_place(self, word, r, c, dr, dc):
        end_r = r + dr * (len(word) - 1)
        end_c = c + dc * (len(word) - 1)
        if not (0 <= end_r < self.height and 0 <= end_c < self.width):
            return False
        for i, ch in enumerate(word):
            rr = r + dr * i
            cc = c + dc * i
            if self.grid[rr][cc] not in ('', ch):
                return False
        return True

    def place(self, word, r, c, dr, dc):
        for i, ch in enumerate(word):
            rr = r + dr * i
            cc = c + dc * i
            self.grid[rr][cc] = ch
        self.placements.append((word, r, c, dr, dc))

    def generate(self, max_attempts=500):
        for word in self.words:
            if len(word) > max(self.width, self.height):
                self.unplaced.append(word)
                continue
            placed = False
            for _ in range(max_attempts):
                r = self.rng.randrange(self.height)
                c = self.rng.randrange(self.width)
                dr, dc = self.rng.choice(self.DIRECTIONS)
                if self.can_place(word, r, c, dr, dc):
                    self.place(word, r, c, dr, dc)
                    placed = True
                    break
            if not placed:
                candidates = []
                for r in range(self.height):
                    for c in range(self.width):
                        for dr, dc in self.DIRECTIONS:
                            if self.can_place(word, r, c, dr, dc):
                                candidates.append((r, c, dr, dc))
                if candidates:
                    r, c, dr, dc = self.rng.choice(candidates)
                    self.place(word, r, c, dr, dc)
                    placed = True
            if not placed:
                self.unplaced.append(word)
        for r in range(self.height):
            for c in range(self.width):
                if self.grid[r][c] == '':
                    self.grid[r][c] = self.rng.choice(FILL_CHARS)

    def print_grid(self, spaced=True):
        for row in self.grid:
            line = ''
            for ch in row:
                w = char_width(ch)
                pad = 2 - w
                if spaced:
                    line += ch + ' ' * (pad + 1)
                else:
                    line += ch + ' ' * pad
            print(line.rstrip())

    def print_answers(self):
        print("\n===== 答案位置 =====")
        for word, r, c, dr, dc in self.placements:
            end_r = r + dr * (len(word) - 1)
            end_c = c + dc * (len(word) - 1)
            print(f"{word:<34} ({r:>2},{c:>2}) {self.DIR_NAMES[(dr, dc)]} ({end_r:>2},{end_c:>2})")
        if self.unplaced:
            print(f"\n未放入的单词（{len(self.unplaced)} 个）：")
            for w in self.unplaced:
                print(f"  - {w}")

def best_generate(width, height, words, seeds=range(300), max_attempts=1500):
    best_gen = None
    best_count = -1
    for seed in seeds:
        gen = WordSearchGenerator(width, height, words, seed=seed)
        gen.generate(max_attempts=max_attempts)
        count = len(gen.placements)
        if count > best_count:
            best_count = count
            best_gen = gen
        if count == len(gen.words):
            break
    return best_gen

# ========== 主程序 ==========
if __name__ == "__main__":
    categories = WORD_LIST
    all_words = list({normalize_word(w) for cat_words in categories.values() for w in cat_words if normalize_word(w)})

    print(f"词库总曲目数：{len(all_words)}")
    for cat, words in categories.items():
        print(f"  {cat}: {len(words)} 首")
    print(f"\n分类权重：{CATEGORY_WEIGHTS}")
    print("maimai 和 Arcaea 的曲目被抽中的概率更高。\n")

    while True:
        size_input = input(f"请输入网格宽高（默认 {DEFAULT_WIDTH}x{DEFAULT_HEIGHT}，直接回车使用默认）：").strip()
        if size_input:
            try:
                w_str, h_str = size_input.lower().split('x')
                width = int(w_str)
                height = int(h_str)
            except:
                print("格式错误，使用默认尺寸。")
                width, height = DEFAULT_WIDTH, DEFAULT_HEIGHT
        else:
            width, height = DEFAULT_WIDTH, DEFAULT_HEIGHT

        num_input = input(f"请输入本次要放入的单词数量（1-{len(all_words)}，默认 120）：").strip()
        if num_input:
            try:
                num = int(num_input)
                num = max(1, min(num, len(all_words)))
            except:
                print("输入无效，使用默认 120。")
                num = min(120, len(all_words))
        else:
            num = min(120, len(all_words))

        selected = weighted_sample_by_category(
            categories, CATEGORY_WEIGHTS, num,
            top_ratio=0.4, hot_weight=3
        )
        print(f"\n本次选取 {len(selected)} 个单词（maimai/Arcaea 优先），生成 {width}x{height} 网格...\n")

        gen = best_generate(width, height, selected, seeds=range(200), max_attempts=MAX_ATTEMPTS)
        print(f"成功放入 {len(gen.placements)} / {len(gen.words)} 个单词\n")
        print("===== 找单词表 =====")
        gen.print_grid(spaced=SPACED)

        if SHOW_ANSWERS:
            gen.print_answers()

        again = input("\n是否继续生成下一个？(y/n，默认 n)：").strip().lower()
        if again != 'y':
            print("退出。")
            break