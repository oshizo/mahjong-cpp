import sys

sys.path.append("./bin")
from mahjongpy import (
    Tile,
    Hand,
    SyantenCalculator,
    ScoreCalculator,
    ExpectedValueCalculator,
)
from enum import Enum


class SyantenType(Enum):
    Null = 0
    Normal = 1
    Tiitoi = 2
    Kokusi = 4


class RuleFlag(Enum):
    Null = 0
    AkaDora = 2
    OpenTanyao = 4


class ExpectedValueCalculatorFlag(Enum):
    Null = 0
    CalcSyantenDown = 1  # 向聴落とし考慮
    CalcTegawari = 2  # 手変わり考慮
    CalcDoubleReach = 4  # ダブル立直考慮
    CalcIppatu = 8  # 一発考慮
    CalcHaiteitumo = 16  # 海底撈月考慮
    CalcUradora = 32  # 裏ドラ考慮
    CalcAkaTileTumo = 64  # 赤牌自摸考慮
    MaximaizeWinProb = 128  # 和了確率を最大化 (指定されていない場合は期待値を最大化)


# 123349m3688p1245s
hand = Hand(
    [
        int(Tile.Manzu1),
        int(Tile.Manzu2),
        int(Tile.Manzu3),
        int(Tile.Manzu3),
        int(Tile.Manzu4),
        int(Tile.Manzu9),
        int(Tile.Pinzu3),
        int(Tile.Pinzu6),
        int(Tile.Pinzu8),
        int(Tile.Pinzu8),
        int(Tile.Sozu1),
        int(Tile.Sozu2),
        int(Tile.Sozu4),
        int(Tile.Sozu5),
    ]
)
print(hand.to_string())

bakaze = Tile.Ton
zikaze = Tile.Ton
turn = 1
syanten_type = SyantenType.Normal.value

flag = (
    ExpectedValueCalculatorFlag.CalcSyantenDown.value
    + ExpectedValueCalculatorFlag.CalcTegawari.value
    + ExpectedValueCalculatorFlag.CalcDoubleReach.value
    + ExpectedValueCalculatorFlag.CalcIppatu.value
    + ExpectedValueCalculatorFlag.CalcHaiteitumo.value
    + ExpectedValueCalculatorFlag.CalcUradora.value
    + ExpectedValueCalculatorFlag.CalcAkaTileTumo.value
    # + ExpectedValueCalculatorFlag.MaximaizeWinProb.value
)
dora_indicators = [Tile.Ton]

exp_value_calculator = ExpectedValueCalculator()
score_calculator = ScoreCalculator()
score_calculator.set_bakaze(bakaze)
score_calculator.set_zikaze(zikaze)
score_calculator.set_dora_indicators(dora_indicators)
_, syanten = SyantenCalculator.calc(hand, syanten_type)
success, candidates = exp_value_calculator.calc(
    hand, score_calculator, dora_indicators, syanten_type, flag
)
print(success)
for cand in candidates:
    print("---")
    print(cand.tile)
    print(cand.tenpai_probs[turn - 1])
    print(cand.win_probs[turn - 1])
    print(cand.exp_values[turn - 1])
    print(cand.required_tiles)
    print(cand.syanten_down)
