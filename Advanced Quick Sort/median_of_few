#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>

void medians_of_few(std::string file_name)
{
    std::string reading_input;
    int total_number_of_squares = 0;
    int total_number_of_element = 0;
    std::vector<int> subarray;
    
    

    
    
    char ch;
    std::fstream fin(file_name, std::fstream::in);
    
    // you re keep scanning the element until you reach to the end of the file.
    while (fin >> std::noskipws >> ch && !fin.eof()) {
        
        //std::cout << ch;
        
        
        
        
        
        // if the charactor is not the next line, then it must be a space or the integer.
        if(ch != '\n' && ch != '[' && ch != ']' && ch != ',')
        {
            reading_input.push_back(ch);
            // if the next chracter dectection returns the empty space, then we have to convert the string into the integer.
            if(fin.peek() == ' ' || fin.peek() == '\n' || fin.eof() || fin.peek() == '[' || fin.peek() == ']' || fin.peek() == ',')
            {
                
                subarray.push_back(std::stoi(reading_input));
                reading_input.clear();
            }
            
            
        }
        else if(ch == '\n')
        {
            std::sort(subarray.begin(), subarray.end());
            int right = 0;
            int left = 0;
            
            // if the size of the subarray has even number of element, then we have to take out the minimum value of the array.
            if(subarray.size() % 2 == 0)
            {
                subarray.erase(subarray.begin());
                
                right = subarray.size() - 1;
                left = 0;
                
                std::cout << subarray[(right - left) / 2] << "\n";
                
                subarray.clear();
            }
            else // if the subarray has the size of odd number then we can get the middle element.
            {
                right = subarray.size() - 1;
                left = 0;
                
                std::cout << subarray[(right - left) / 2] << "\n";
                
                subarray.clear();
            }
        }
        
    }
    
    
    
}


/*
 Write an O(1) implementation of the function median_of_few, which takes in a
 nonempty integer array A of length at most 5, and returns its median.
 */

/*void median_of_few(std::vector<int> target_vector)
{
    int left = 0;
    int right = 0;
    
    std::vector<int> collections_of_median;
    
    for(int i = 0; i < (target_vector.size() / 5); ++i)
    {
        left = right;
        right = left + 5;
        
        // this is the formula you re sorting each subarray has the 5 element in the array.
        std::sort(target_vector.begin() + left, target_vector.begin() + right);
        
        // push back the median from each subarray.
        collections_of_median.push_back(target_vector[2 + 5*i]);
        
        
        
        
    }
    
    
}*/


int main()
{
    std::string file_name = "/Users/gihyeonroh/Downloads/data_a.txt";
    medians_of_few(file_name);
    
    
    return 0;
    
}
