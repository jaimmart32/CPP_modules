#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <ctime>


void fill_containers(int argc, char **argv, std::vector<int> &vNumbers, std::list<int> &lNumbers);
void display_info(std::vector<int> &vNumbers, std::list<int> &lNumbers, double v_duration);

void mergeInsertionSort(std::vector<int> &numbers, int insertion_limit);

#endif