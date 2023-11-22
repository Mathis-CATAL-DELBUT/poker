#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#define RED "\x1b[31m"
#define RESET "\x1b[0m"

int good_synthaxe(std::string cards, int char_number)
{
    int good_synthaxe = 0;
    if (cards.size() != char_number)
        good_synthaxe = 1;
    std::string synthaxe_card = "AKQJT98765432";
    std::string synthaxe_color = "HDCS";
    for (int i = 0; i < char_number; i++)
    {
        for (int j = 0; j < synthaxe_card.size(); j++)
        {
            if (cards[i] == synthaxe_card[j])
                break;
            if (j == synthaxe_card.size() - 1)
                good_synthaxe = 1;
        }
        i++;
        for (int j = 0; j < synthaxe_color.size(); j++)
        {
            if (cards[i] == synthaxe_color[j])
            {
                break;
            }
            if (j == synthaxe_color.size() - 1)
                good_synthaxe = 1;
        }
    }
    if (good_synthaxe == 1)
    {
        std::cout << RED << "Bad synthaxe, try again" << RESET << std::endl;
        return (1);
    }
    return (0);
}

void set_cards(std::string *cards)
{
    std::string card;
    do
    {
        std::cout 
        << "Heart(coeur) = H / Diamond(carreau) = D / Spade(pique) = S / Club(trefle) = C\n"
        << "Enter your cards like this 'AS2D': ";
        std::cin >> card;
    } while (good_synthaxe(card, 4) == 1);
    *cards = card;
}

void set_flop(std::string *flop)
{
    std::string flop_cards;
    do
    {
        std::cout 
        << "Heart(coeur) = H / Diamond(carreau) = D / Spade(pique) = S / Club(trefle) = C\n"
        << "Enter the flop like this 'AS2D3C': ";
        std::cin >> flop_cards;
    } while (good_synthaxe(flop_cards, 6));
    *flop = flop_cards;
}

void set_turn(std::string *turn)
{
    std::string turn_card;
    do
    {
        std::cout 
        << "Heart(coeur) = H / Diamond(carreau) = D / Spade(pique) = S / Club(trefle) = C\n"
        << "Enter the turn like this 'AD': ";
        std::cin >> turn_card;
    } while (good_synthaxe(turn_card, 2));
    *turn = turn_card;
}

void set_river(std::string *river)
{
    std::string river_card;
    do
    {
        std::cout 
        << "Heart(coeur) = H / Diamond(carreau) = D / Spade(pique) = S / Club(trefle) = C\n"
        << "Enter the river like this 'AD': ";
        std::cin >> river_card;
    } while (good_synthaxe(river_card, 2));
    *river = river_card;
}

int is_height(std::string cards, std::string flop_turn_river)
{
    std::string height;
    for (int i = 0; i < cards.size(); i++)
    {
        if (cards[i] != 'H' && cards[i] != 'D' && cards[i] != 'S' && cards[i] != 'C')
        {
            height += cards[i];
        }
    }
    for (int i = 0; i < flop_turn_river.size(); i++)
    {
        if (flop_turn_river[i] != 'H' && flop_turn_river[i] != 'D' && flop_turn_river[i] != 'S' && flop_turn_river[i] != 'C')
        {
            height += flop_turn_river[i];
        }
    }
    std::__wrap_iter<char *> oue = std::max_element(height.begin(), height.end());
    const char *oui = &*oue;
    std::cout << "more height: " << oui << std::endl;
    return (0);
}


int main()
{
    std::string flop;
    std::string turn;
    std::string river;
    std::string cards;
    std::string flop_river_turn;    
    set_cards(&cards);
    set_flop(&flop);
    set_turn(&turn);
    set_river(&river);
    flop_river_turn = flop + turn + river;
    // is_quinte_flush_royal(cards, flop_river_turn);
    // is_quinte_flush(cards, flop_river_turn);
    // is_carre(cards, flop_river_turn);
    // is_full(cards, flop_river_turn);
    // is_flush(cards, flop_river_turn);
    // is_quinte(cards, flop_river_turn);
    // is_brelan(cards, flop_river_turn);
    // is_double_paire(cards, flop_river_turn);
    // is_paire(cards, flop_river_turn);
    is_height(cards, flop_river_turn);
}