#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <ctime>

bool validate_args(int argc, char **argv);
void fill_containers(int argc, char **argv, std::vector<int> &vNumbers, std::list<int> &lNumbers);
void before_display_info(std::vector<int> &vNumbers, std::list<int> &lNumbers);
void after_display_info(std::vector<int> &vNumbers, std::list<int> &lNumbers, double v_duration, double l_duration);

void mergeInsertionSort(std::vector<int> &numbers, int insertion_limit);
void l_mergeInsertionSort(std::list<int> &numbers, int insertion_limit);

#endif