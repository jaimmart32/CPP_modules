#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>
#include <iostream>


void fill_containers(int argc, char **argv, std::vector<int> &vNumbers, std::list<int> &lNumbers);
void display_info(std::vector<int> &vNumbers, std::list<int> &lNumbers);
#endif