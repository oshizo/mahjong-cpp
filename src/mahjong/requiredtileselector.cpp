#include "requiredtileselector.hpp"

#include "syanten.hpp"

namespace mahjong {

std::vector<int> RequiredTileSelector::select_normal(const Hand &hand)
{
    std::vector<int> tiles;
    tiles.reserve(14);
    Hand hand_after = hand; // 自摸後の手牌

    // 現在の向聴数を計算する。
    int syanten = SyantenCalculator::calc_normal(hand);
    if (syanten == -1)
        return {}; // 和了形

    // 自摸後に向聴数が減少した牌を列挙する。ただし、4枚持ちの場合は除く。
    for (int i = 0; i < 9; ++i) {
        if ((hand.manzu & Bit::mask[i]) != Bit::tile4[i]) {
            hand_after.manzu += Bit::tile1[i];
            if (syanten > SyantenCalculator::calc_normal(hand_after))
                tiles.push_back(i);
            hand_after.manzu -= Bit::tile1[i];
        }

        if ((hand.pinzu & Bit::mask[i]) != Bit::tile4[i]) {
            hand_after.pinzu += Bit::tile1[i];
            if (syanten > SyantenCalculator::calc_normal(hand_after))
                tiles.push_back(i + Tile::Pinzu1);
            hand_after.pinzu -= Bit::tile1[i];
        }

        if ((hand.sozu & Bit::mask[i]) != Bit::tile4[i]) {
            hand_after.sozu += Bit::tile1[i];
            if (syanten > SyantenCalculator::calc_normal(hand_after))
                tiles.push_back(i + Tile::Sozu1);
            hand_after.sozu -= Bit::tile1[i];
        }
    }

    for (int i = 0; i < 7; ++i) {
        if ((hand.zihai & Bit::mask[i]) != Bit::tile4[i]) {
            hand_after.zihai += Bit::tile1[i];
            if (syanten > SyantenCalculator::calc_normal(hand_after))
                tiles.push_back(i + Tile::Ton);
            hand_after.zihai -= Bit::tile1[i];
        }
    }

    return tiles;
}

std::vector<int> RequiredTileSelector::select_tiitoi(const Hand &hand)
{
    std::vector<int> tiles;
    tiles.reserve(14);
    Hand hand_after = hand; // 自摸後の手牌

    // 現在の向聴数を計算する。
    int syanten = SyantenCalculator::calc_tiitoi(hand);
    if (syanten == -1)
        return {}; // 和了形

    // 自摸後に向聴数が減少した牌を列挙する。ただし、4枚持ちの場合は除く。
    for (int i = 0; i < 9; ++i) {
        if ((hand.manzu & Bit::mask[i]) != Bit::tile4[i]) {
            hand_after.manzu += Bit::tile1[i];
            if (syanten > SyantenCalculator::calc_tiitoi(hand_after))
                tiles.push_back(i);
            hand_after.manzu -= Bit::tile1[i];
        }

        if ((hand.pinzu & Bit::mask[i]) != Bit::tile4[i]) {
            hand_after.pinzu += Bit::tile1[i];
            if (syanten > SyantenCalculator::calc_tiitoi(hand_after))
                tiles.push_back(i + Tile::Pinzu1);
            hand_after.pinzu -= Bit::tile1[i];
        }

        if ((hand.sozu & Bit::mask[i]) != Bit::tile4[i]) {
            hand_after.sozu += Bit::tile1[i];
            if (syanten > SyantenCalculator::calc_tiitoi(hand_after))
                tiles.push_back(i + Tile::Sozu1);
            hand_after.sozu -= Bit::tile1[i];
        }
    }

    for (int i = 0; i < 7; ++i) {
        if ((hand.zihai & Bit::mask[i]) != Bit::tile4[i]) {
            hand_after.zihai += Bit::tile1[i];
            if (syanten > SyantenCalculator::calc_tiitoi(hand_after))
                tiles.push_back(i + Tile::Ton);
            hand_after.zihai -= Bit::tile1[i];
        }
    }

    return tiles;
}

std::vector<int> RequiredTileSelector::select_kokusi(const Hand &hand)
{
    std::vector<int> tiles;
    tiles.reserve(14);
    Hand hand_after = hand; // 自摸後の手牌

    // 現在の向聴数を計算する。
    int syanten = SyantenCalculator::calc_kokusi(hand);
    if (syanten == -1)
        return {}; // 和了形

    // 自摸後に向聴数が減少した牌を列挙する。ただし、4枚持ちの場合は除く。
    for (int i = 0; i < 9; i += 8) {
        if ((hand.manzu & Bit::mask[i]) != Bit::tile4[i]) {
            hand_after.manzu += Bit::tile1[i];
            if (syanten > SyantenCalculator::calc_kokusi(hand_after))
                tiles.push_back(i);
            hand_after.manzu -= Bit::tile1[i];
        }

        if ((hand.pinzu & Bit::mask[i]) != Bit::tile4[i]) {
            hand_after.pinzu += Bit::tile1[i];
            if (syanten > SyantenCalculator::calc_kokusi(hand_after))
                tiles.push_back(i + Tile::Pinzu1);
            hand_after.pinzu -= Bit::tile1[i];
        }

        if ((hand.sozu & Bit::mask[i]) != Bit::tile4[i]) {
            hand_after.sozu += Bit::tile1[i];
            if (syanten > SyantenCalculator::calc_kokusi(hand_after))
                tiles.push_back(i + Tile::Sozu1);
            hand_after.sozu -= Bit::tile1[i];
        }
    }

    for (int i = 0; i < 7; ++i) {
        if ((hand.zihai & Bit::mask[i]) != Bit::tile4[i]) {
            hand_after.zihai += Bit::tile1[i];
            if (syanten > SyantenCalculator::calc_kokusi(hand_after))
                tiles.push_back(i + Tile::Ton);
            hand_after.zihai -= Bit::tile1[i];
        }
    }

    return tiles;
}

} // namespace mahjong
