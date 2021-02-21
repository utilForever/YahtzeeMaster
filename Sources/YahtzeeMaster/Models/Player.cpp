// Copyright (c) 2020 Chris Ohk

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <YahtzeeMaster/Enums/GameEnums.hpp>
#include <YahtzeeMaster/Models/Player.hpp>

#include <algorithm>

namespace YahtzeeMaster
{
void Player::Initialize()
{
    m_scores.fill(0);
    m_numRoll = 0;
}

const ScoreCard& Player::GetScoreCard() const
{
    return m_scoreCard;
}

std::array<int, NUM_DICES> Player::GetDiceValues() const
{
    std::array<int, NUM_DICES> ret{};

    for (std::size_t i = 0; i < ret.size(); ++i)
    {
        ret[i] = m_dices[i].GetValue();
    }

    return ret;
}

std::array<int, NUM_CATEGORIES> Player::GetScores() const
{
    return m_scores;
}

int Player::GetRemainReroll() const
{
    return NUM_ROLLS - m_numRoll;
}

void Player::SetDiceValues(std::vector<int> diceValues)
{
    std::sort(diceValues.begin(), diceValues.end());

    std::size_t i = 0;

    for (const int& diceValue : diceValues)
    {
        m_dices[i].SetValue(diceValue);
        ++i;
    }
}

void Player::RollDices(std::vector<int> rerollValues)
{
    if (m_numRoll == NUM_ROLLS)
    {
        return;
    }

    if (rerollValues.empty())
    {
        for (int i = 0; i < NUM_DICES; ++i)
        {
            m_dices[i].Roll();
        }
    }
    else
    {
        std::sort(rerollValues.begin(), rerollValues.end());

        std::size_t i = 0, j = 0;
        std::vector<std::size_t> indices;
        indices.reserve(rerollValues.size());

        while (i < rerollValues.size() && j < m_dices.size())
        {
            const int diff = rerollValues.at(i) - m_dices.at(j).GetValue();

            if (diff == 0)
            {
                indices.emplace_back(j);

                ++i;
                ++j;
            }
            else if (diff > 0)
            {
                ++i;
            }
            else
            {
                ++j;
            }
        }

        for (auto& index : indices)
        {
            m_dices[index].Roll();
        }
    }

    std::sort(m_dices.begin(), m_dices.end(),
              [](const Dice& a, const Dice& b) { return a.GetValue() < b.GetValue(); });

    CalculateScores();

    ++m_numRoll;
}

void Player::CalculateScores()
{
    // Initialize scores
    m_scores.fill(0);

    std::array<int, NUM_DICES> values{};
    int sumOfAllDice = 0;

    for (std::size_t i = 0; i < NUM_DICES; ++i)
    {
        values[i] = m_dices[i].GetValue();
        sumOfAllDice += values[i];

        // Calculate upper section
        m_scores[Category::ACES] += (values[i] == 1) ? 1 : 0;
        m_scores[Category::TWOS] += (values[i] == 2) ? 2 : 0;
        m_scores[Category::THREES] += (values[i] == 3) ? 3 : 0;
        m_scores[Category::FOURS] += (values[i] == 4) ? 4 : 0;
        m_scores[Category::FIVES] += (values[i] == 5) ? 5 : 0;
        m_scores[Category::SIXES] += (values[i] == 6) ? 6 : 0;
    }

    // Calculate lower section
    m_scores[Category::THREE_OF_A_KIND] =
        ScoreCard::IsThreeOfAKind(values) ? sumOfAllDice : 0;
    m_scores[Category::FOUR_OF_A_KIND] =
        ScoreCard::IsFourOfAKind(values) ? sumOfAllDice : 0;
    m_scores[Category::FULL_HOUSE] = ScoreCard::IsFullHouse(values) ? 25 : 0;
    m_scores[Category::SMALL_STRAIGHT] = ScoreCard::IsSmallStraight(values) ? 30 : 0;
    m_scores[Category::LARGE_STRAIGHT] = ScoreCard::IsLargeStraight(values) ? 40 : 0;
    m_scores[Category::YAHTZEE] = ScoreCard::IsFourOfAKind(values) ? 50 : 0;
    m_scores[Category::CHANCE] = sumOfAllDice;
}

void Player::FillScoreCard(Category category)
{
    const bool isFillSuccess = m_scoreCard.FillScore(category, m_scores[category]);
    if (isFillSuccess)
    {
        processNextPlayerCallback();
    }
}
}  // namespace YahtzeeMaster