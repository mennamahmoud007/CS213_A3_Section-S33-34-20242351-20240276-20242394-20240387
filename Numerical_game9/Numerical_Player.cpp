#include "Numerical_Player.h"
#include "Numerical_Board.h"
#include <iostream>

Move<int>* NumericalPlayer::get_computer_move() {
    if (!boardPtr) return nullptr;

    NumericBoard* nb = dynamic_cast<NumericBoard*>(boardPtr);
    if (!nb) return nullptr;

    auto cells = nb->available_cells();
    auto nums_all = nb->available_nums();

    // Filter numbers by parity rule
    std::vector<int> nums;
    for (int v : nums_all) {
        if (number_allowed(v)) nums.push_back(v);
    }

    if (cells.empty() || nums.empty()) return nullptr;

    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        seeded = true;
    }

    auto chosen_cell = cells[std::rand() % cells.size()];
    int chosen_num = nums[std::rand() % nums.size()];

    std::cout << "[CPU] " << get_name() << " plays " << chosen_num
              << " at (" << chosen_cell.first << "," << chosen_cell.second << ")\n";

    return new Move<int>(chosen_cell.first, chosen_cell.second, chosen_num);
}
