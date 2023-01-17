#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <string>
#include <algorithm>


/*
 Implement the greedy algorithm for the knapsack problem with replacement, where the “greediness” condition is that you keep taking the object with the highest value per weight ratio (this algorithm doesn’t give the optimal value), and if there’s a tie for higher ratio, take the object with the highest value.
 Call this function greedy_knapsack. The input is an array of pairs (value, weight), where
 both value and weight are positive integers, and a positive integer W. Apply greedy_knapsack to each row of data_c.txt, and output each result as a row of submission_c.txt.
 
 */

void reading_the_values(std::string file_name)
{
    std::string reading_input;
    char ch;
    std::fstream fin(file_name, std::fstream::in);
    std::pair<double, int> collections_of_ratio_weight;
    std::vector<std::pair<double, int>> array_of_pairs;
    std::vector<std::pair<int, int>> final_result;
    std::pair<int, int> result_storage;
    
    int knapsack_capacity = 0;
    double value_input = -1;
    int weight_input = -1;
    
    
    // you re keep scanning the element until you reach to the end of the file.
    while (fin >> std::noskipws >> ch && !fin.eof())
    {
        
        
        
        // if the charactor is not the next line, then it must be a space or the integer.
        if(ch != '\n' && ch != '[' && ch != ']' && ch != ',' && ch != '(' && ch != ')' && ch != ' ')
        {
            reading_input.push_back(ch);
            // if the next chracter dectection returns the empty space, then we have to convert the string into the integer.
            if(fin.peek() == ' ' || fin.peek() == '\n' || fin.eof() || fin.peek() == '[' || fin.peek() == ']' || fin.peek() == ',' || fin.peek() == '(' || fin.peek() == ')')
            {
                
                // now you re inputing the value first in the first slot of the pair.
                if(value_input == -1 && weight_input == -1)
                {
                    value_input = std::stod(reading_input);
                    
                    // then we have to update the ratio of the pair
                    collections_of_ratio_weight.first = value_input;
                    
                }
                else if(value_input != -1 && weight_input == -1)
                {
                    weight_input= std::stoi(reading_input);
                    
                    collections_of_ratio_weight.second = weight_input;
                    collections_of_ratio_weight.first = value_input / weight_input;
                    
                    array_of_pairs.push_back(collections_of_ratio_weight);
                    
                    value_input = -1;
                    weight_input = -1;
                }
                
                
                reading_input.clear();
            }
            
            
        }
        else if(ch == ')') // if the ch catches the character where ends the array, then now we have to get the pivot value from the file and then do the partitioning process.
        {
            if(fin.peek() == ']')
            {
                // now catch the pivot element
                while (fin >> std::noskipws >> ch && !fin.eof())
                {
                    if(ch != '\n' && ch != '[' && ch != ']' && ch != ',' && ch != '(' && ch != ')')
                    {
                        reading_input.push_back(ch);
                        
                        if(fin.peek() == ' ' || fin.peek() == '\n' || fin.eof() || fin.peek() == '[' || fin.peek() == ']' || fin.peek() == ',' || fin.peek() == '(' || fin.peek() == ')')
                        {
                            knapsack_capacity = std::stoi(reading_input);
                            reading_input.clear();
                        }
                    }
                    else if(ch == ')') // if the ch catch the real end of the line, then you will now proceed to find the tuple.
                    {
                        // since at this point, you have the knapsack capacity and then array of pairs, now you have to calculate which one is the best options.
                        
                        std::sort(array_of_pairs.begin(), array_of_pairs.end());
                        
                        // runs the loop until capacity of the Knapsack is more than 0
                        
                            for(int i = array_of_pairs.size() - 1; i >= 0; --i)
                            {
                                // if the weight of the object is less than the knapsack capacity, then take the value.
                                if(array_of_pairs[i].second <= knapsack_capacity)
                                {
                                    
                                    
                                    result_storage.first = array_of_pairs[i].first * array_of_pairs[i].second;
                                    
                                    result_storage.second = array_of_pairs[i].second;
                                    
                                    for(int j = 0; j < knapsack_capacity / array_of_pairs[i].second; ++j)
                                    {
                                        final_result.push_back(result_storage);
                                    }
                                    
                                    knapsack_capacity = knapsack_capacity % array_of_pairs[i].second;
                                    
                                }
                            }
                            
                            
                        
                        
                        
                        // once the calculation is done, we need to print out which element has been used.
                        
                        std::cout << '\n' << '[';
                        
                        if(final_result.size() > 0)
                        {
                            for(int i = 0; i < final_result.size() - 1; ++i)
                            {
                                std::cout << '(' << final_result[i].first << ", " << final_result[i].second << "), ";
                            }
                            
                            std::cout << '(' << final_result[final_result.size() - 1].first << ", " << final_result[final_result.size() - 1].second << ")]";
                        }
                        else
                        {
                            std::cout << ']';
                        }
                        
                        final_result.clear();
                        array_of_pairs.clear();
                        value_input = -1;
                        weight_input = -1;
                    
                        break;
                    }
                }
            }
            
            
            
            
        }
        
    }

            
            
}
    
    
    



int main()
{
    // first we have to create the 2d vector.
    std::string file_name = "/Users/gihyeonroh/Downloads/HW4 data_a.txt";
    reading_the_values(file_name);
    
        
    
    
    
    
    
    
    
    
    
    return 0;
}



/*
 
 std::vector<int> initialization(Knapsack_capacity + 1);
 
 
 // once you re finished to get the input from those two vectors, then based on the size we are provided, we will create a 2d vector.
 
 std::vector<std::vector<int>> value_table(values.size(), initialization);
 
 
 
 // once you re finished to initialized the 2d vector, then now you have to implement the algorithm to find the max possible Knapsack weight.
 */


/*
 int weight_input = 0;
 double value_input = 0;
 int Knapsack_capacity = 0;
 size_t total_value_of_knapsack = 0;
 
 std::vector<std::pair<double, int>> array_of_pairs;
 std::pair<double, int> pair_of_value_weight;
 std::vector<std::pair<int,int>> final_result;
 std::pair<int, int> result_storage;

 
 for(int i = 0; i < 2; ++i)
 {
     std::cin >> value_input >> weight_input;
     pair_of_value_weight.first = value_input / weight_input;
     pair_of_value_weight.second = weight_input;
         
     array_of_pairs.push_back(pair_of_value_weight);
 }
 
 // once you re finished storing the values into the array, then
 
 std::cin >> Knapsack_capacity;
 
 int Knapsack_copy = Knapsack_capacity;
 
 std::sort(array_of_pairs.begin(), array_of_pairs.end());
 
 // runs the loop until capacity of the Knapsack is more than 0
 
     for(int i = array_of_pairs.size() - 1; i >= 0; --i)
     {
         // if the weight of the object is less than the knapsack capacity, then take the value.
         if(array_of_pairs[i].second <= Knapsack_copy)
         {
             total_value_of_knapsack += (Knapsack_copy / array_of_pairs[i].second) * array_of_pairs[i].first;
             
             
             
             result_storage.first = array_of_pairs[i].first * array_of_pairs[i].second;
             
             result_storage.second = array_of_pairs[i].second;
             
             for(int j = 0; j < Knapsack_copy / array_of_pairs[i].second; ++j)
             {
                 final_result.push_back(result_storage);
             }
             
             Knapsack_copy = Knapsack_copy % array_of_pairs[i].second;
             
         }
     }
     
     
 
 
 
 // once the calculation is done, we need to print out which element has been used.
 
 std::cout << '\n' << '[';
 
 if(final_result.size() > 0)
 {
     for(int i = 0; i < final_result.size() - 1; ++i)
     {
         std::cout << '(' << final_result[i].first << ", " << final_result[i].second << "), ";
     }
     
     std::cout << '(' << final_result[final_result.size() - 1].first << ", " << final_result[final_result.size() - 1].second << ")]";
 }
 else
 {
     std::cout << ']';
 }
 
 
 */
