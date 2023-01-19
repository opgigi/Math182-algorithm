#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>


void read_input_from_file(std::string file_name)
{
    std::vector<std::vector<int>> change_table;
    int copy_of_worth_price_target = 0;
    std::vector<int> list_of_coins;
    std::string reading_input;
    std::vector<int> used_coin;
    int worth_price_target = 0;
    
    list_of_coins.push_back(0);
    
    char ch;
    std::fstream fin(file_name, std::fstream::in);
    
    // you re keep scanning the element until you reach to the end of the file.
    while (fin >> std::noskipws >> ch && !fin.eof())
    {
        
        
        // if the charactor is not the next line, then it must be a space or the integer.
        if(ch != '\n' && ch != '[' && ch != ']' && ch != ',' && ch != '(' && ch != ')')
        {
            reading_input.push_back(ch);
            // if the next chracter dectection returns the empty space, then we have to convert the string into the integer.
            if(fin.peek() == ' ' || fin.peek() == '\n' || fin.eof() || fin.peek() == '[' || fin.peek() == ']' || fin.peek() == ',' || fin.peek() == '(' || fin.peek() == ')')
            {
                
                list_of_coins.push_back(std::stoi(reading_input));
                reading_input.clear();
            }
            
            
        }
        else if(ch == ']') // if the ch catches the character where ends the array, then now we have to get the pivot value from the file and then do the partitioning process.
        {
            // now catch the pivot element
            while (fin >> std::noskipws >> ch && !fin.eof())
            {
                if(ch != '\n' && ch != '[' && ch != ']' && ch != ',' && ch != '(' && ch != ')')
                {
                    reading_input.push_back(ch);
                    
                    if(fin.peek() == ' ' || fin.peek() == '\n' || fin.eof() || fin.peek() == '[' || fin.peek() == ']' || fin.peek() == ',' || fin.peek() == '(' || fin.peek() == ')')
                    {
                        worth_price_target = std::stoi(reading_input);
                        reading_input.clear();
                        
                        std::sort(list_of_coins.begin(), list_of_coins.end());
                        
                        // and define the array of each situation.
                        std::vector<int> dp(worth_price_target + 1, INT_MAX);
                        dp[0] = 0;
                        
                        std::vector<int> bottom_line(worth_price_target + 1);
                        
                        change_table.push_back(bottom_line);
                        
                        for(int i = 1; i < list_of_coins.size(); ++i)
                        {
                            for(int j = list_of_coins[i]; j <= worth_price_target; ++j)
                            {
                                
                                dp[j] = std::min(dp[j], dp[j - list_of_coins[i]] + 1);
                                
                                
                            }
                            
                            /*
                             once you calculate all the optimal minimums for the change, then you have to fill the table and we will going to use back_tracking method.
                             */
                             
                            change_table.push_back(dp);
                            
                        }
                        
                       // now we are going to start from the very last slots of the 2D array. and what you do is that you re going to compare with the values on the same column location but has the different row in the table.
                        
                        int row_index = change_table.size() - 1;
                        int column_index = change_table[0].size() - 1;
                        
                        
                        while(change_table[row_index][column_index] > 0)
                        {
                            // if the optimal changes outcomes are the same from the set, S, S-{coin[row_index]}, then you gotta go up.
                            if(change_table[row_index][column_index] == change_table[row_index - 1][column_index])
                            {
                                --row_index;
                            }
                            else // if the optimal changes outcome are different from the set S, S-{last_row_index}, then that's where does makes the change. thus we are going to back tracking by the coin.
                            {
                                // then update the column and then also we gotta go up to the upper row to finds
                                
                                
                                if(list_of_coins[row_index] <= column_index)
                                {
                                    
                                    used_coin.push_back(list_of_coins[row_index]);
                                }
                                
                                column_index = column_index - list_of_coins[row_index];
                                
                            }
                        }
                        
                        
                        // now print out the list of coins are used for the worth price target
                        std::cout << '[';
                        
                        for(int i = 0; i < used_coin.size() - 1; ++i)
                        {
                            std::cout << used_coin[i] << ", ";
                        }
                        
                        std::cout << used_coin[used_coin.size() - 1] << ']' << '\n';
                        
                        
                        dp.clear();
                        list_of_coins.clear();
                        list_of_coins.push_back(0);
                        used_coin.clear();
                        change_table.clear();
                        
                        //std::cout << "\nthe minimum number of coins has to be used is: " << dp[worth_price_target] << '\n';
                        
                    }
                }
                else if(ch == ')') // if the ch catch the real end of the line, then you will now proceed to find the tuple.
                {
                    
                
                    
                    
                    break;
                }
            }
            
            
            
        }
        
    }
}


/*
 so the principle of this problem is that, let's say you are going to use the smallest value of the coin to change the worth from 1 to 149.
 
 let coins = {1, 32, 35, 34, 25, 24, 15, 13, 42, 27, 47, 8 }
 
 then, after the first execution you will have:
 
 1 , 2 , 3 , 4 , 5, 6 , ..... , 145, 146, 147, 148, 149
 
 now, after the first execution, we will now renew every single slots within the new elements from the list of coins.
 
 in this case, the second one will be the coin worth of 8:
 remember the equation = dp[j] = std::min(dp[j], dp[j - list_of_coins[i]);
 
 then now dp will compare, will decide, what's the best change value for the dp.
 
 for example, when j = 8, then the dp[8] will take the minimum between 8 or dp[8-8] + 1
 in the case of the dp[8], the current value is 8.
 
 
 
 */


int main()
{
    int worth_price_Target = 0;
    int numbers_of_coin = 0;
    int user_input = 0;
    int copy_of_worth_price_target = 0;
    std::vector<int> list_of_coins;
    std::vector<int> array_for_inputs;
    std::vector<std::vector<int>> change_table;
    std::vector<int> used_coin;
    
    std::vector<int> collections_of_input;
    std::string file_name = "/Users/gihyeonroh/Downloads/data_a (HW 3).txt";
    read_input_from_file(file_name);
    
    
    
    
    
    
    
    
    
    
}


/*
 std::sort(list_of_coins.begin(), list_of_coins.end());
 
 // and define the array of each situation.
 std::vector<int> dp(worth_price_Target + 1, INT_MAX);
 dp[0] = 0;
 
 std::vector<int> bottom_line(worth_price_Target + 1);
 
 change_table.push_back(bottom_line);
 
 for(int i = 1; i < list_of_coins.size(); ++i)
 {
     copy_of_worth_price_target = dp[worth_price_Target];
     for(int j = list_of_coins[i]; j <= worth_price_Target; ++j)
     {
         
         dp[j] = std::min(dp[j], dp[j - list_of_coins[i]] + 1);
         
         
     }
     
     /*
      once you calculate all the optimal minimums for the change, then you have to fill the table and we will going to use back_tracking method.
      
     change_table.push_back(dp);
     
 }
 
// now we are going to start from the very last slots of the 2D array. and what you do is that you re going to compare with the values on the same column location but has the different row in the table.
 
 int row_index = change_table.size() - 1;
 int column_index = change_table[0].size() - 1;
 
 
 while(change_table[row_index][column_index] > 0)
 {
     // if the optimal changes outcomes are the same from the set, S, S-{coin[row_index]}, then you gotta go up.
     if(change_table[row_index][column_index] == change_table[row_index - 1][column_index])
     {
         --row_index;
     }
     else // if the optimal changes outcome are different from the set S, S-{last_row_index}, then that's where does makes the change. thus we are going to back tracking by the coin.
     {
         // then update the column and then also we gotta go up to the upper row to finds
         column_index = column_index - list_of_coins[row_index];
         used_coin.push_back(list_of_coins[row_index]);
     }
 }
 
 
 // now print out the list of coins are used for the worth price target
 std::cout << '\n' << '[';
 
 for(int i = 0; i < used_coin.size() - 1; ++i)
 {
     std::cout << used_coin[i] << ", ";
 }
 
 std::cout << used_coin[used_coin.size() - 1] << ']' << '\n' << '\n';
 
 
 
 
 std::cout << "\nthe minimum number of coins has to be used is: " << dp[worth_price_Target] << '\n';
 
 
 */
