#ifndef GAME_H
#define GAME_H

#include <vector>
#include <chrono>
#include "card.h"
#include "card_deck.h"
#include "card_stack.h"
#include "command.h"

const int DECKS_COUNT = 4;
const int STACKS_COUNT = 7;
const int ALL_CARDS_COUNT = 52;
const int CARDS_PER_PACK = 13;

class Game {
    CardDeck main_card_deck {ALL_CARDS_COUNT};
    CardDeck discard_card_deck {ALL_CARDS_COUNT};

    CardDeck target_card_decks [DECKS_COUNT] = { CardDeck {CARDS_PER_PACK, Color::SPADES} , CardDeck {CARDS_PER_PACK, Color::DIAMONDS}, CardDeck {CARDS_PER_PACK, Color::HEARTS}, CardDeck {CARDS_PER_PACK, Color::CLUBS}};
    CardStack working_card_stacks [STACKS_COUNT] = { CardStack {CARDS_PER_PACK}, CardStack {CARDS_PER_PACK}, CardStack {CARDS_PER_PACK},
                                                    CardStack {CARDS_PER_PACK}, CardStack {CARDS_PER_PACK}, CardStack {CARDS_PER_PACK}, CardStack {CARDS_PER_PACK}};
    int score;
    bool paused;
    std::chrono::high_resolution_clock::time_point started_at;
    std::chrono::high_resolution_clock::time_point paused_at;
    CommandManager command_manager;
    static int games_counter;
    public:
    Game();
    CardDeck get_target_deck_by_id(int index);
    CardStack get_working_stack_by_id(int index);
    CardDeck get_main_card_deck();
    CardDeck get_discard_card_deck();
    bool save(std::string filename);
    static Game * load(std::string filename);
    int get_score();
    int get_moves_count();
    void start();
    void pause();
    void resume();

    void undo();
    bool get_card_from_main_deck_to_discard_deck();
    bool move_card_from_discard_deck_to_working_stack(int stack_index);
    bool move_card_from_discard_deck_to_target_deck(int deck_index);
    bool move_card_from_target_deck_to_working_stack(int deck_index, int stack_index);
    bool move_card_from_working_stack_to_target_deck(int stack_index, int deck_index);
    bool move_cards_from_working_stack_to_working_stack(int src_stack_index , int dest_stack_index, int card_index);
    std::chrono::seconds get_total_time_in_seconds();

static int get_games_count();
};

#endif // GAME_H
