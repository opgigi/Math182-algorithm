#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

/*
 Write an O(n) implementation of the function partition_at, which takes in an integer array A and an integer k, and returns a tuple (A<, A>) of two arrays, where A< is the subsequence of entries of A which are less than k, and A> is the subsequence of entries of A which are greater than k.
 */

// this is the partitionint process.
void partition_at(std::vector<int> collections_of_input, int pivot)
{
    std::vector<int> partition_left;
    std::vector<int> partition_right;
    // first you need to find an index where do we have to separate the array.
    
    
    for(int index = 0; index < collections_of_input.size(); ++index)
    {
        if(collections_of_input[index] < pivot)
        {
            partition_left.push_back(collections_of_input[index]);
        }
        else if(pivot < collections_of_input[index])
        {
            partition_right.push_back(collections_of_input[index]);
        }
        else
        {
            // do nothing.
        }
    }
    
    // once you re done with the partitioning process, now you have to print out the partition outcome from left and right side.
    
    // open the oprand
    std::cout << '(';
    
    // printing out the partition of the left
    
    if(partition_left.size() > 0)
    {
        std::cout << '[';
        
        for(int i = 0; i < partition_left.size() - 1; ++i)
        {
            std::cout << partition_left[i] << ',' << " ";
        }
        
        std::cout << partition_left[partition_left.size() - 1] << ']' << ',' << " ";
    }
    
    if(partition_right.size() > 0)
    {
        std::cout << '[';
        
        for(int i = 0; i < partition_right.size() - 1; ++i)
        {
            std::cout << partition_right[i] << ',' << " ";
        }
        
        std::cout << partition_right[partition_right.size() - 1] << ']';
    }
    
     std::cout << ')' << '\n';
    
}

void read_input_from_file(std::string file_name)
{
    std::string reading_input;
    std::vector<int> collections_of_input;
    int pivot = 0;
    int left = 0;
    int right = 0;
    
    

    
    
    char ch;
    std::fstream fin(file_name, std::fstream::in);
    
    // you re keep scanning the element until you reach to the end of the file.
    while (fin >> std::noskipws >> ch && !fin.eof()) {
        
        //std::cout << ch;
        
        
        
        
        
        // if the charactor is not the next line, then it must be a space or the integer.
        if(ch != '\n' && ch != '[' && ch != ']' && ch != ',' && ch != '(' && ch != ')')
        {
            reading_input.push_back(ch);
            // if the next chracter dectection returns the empty space, then we have to convert the string into the integer.
            if(fin.peek() == ' ' || fin.peek() == '\n' || fin.eof() || fin.peek() == '[' || fin.peek() == ']' || fin.peek() == ',' || fin.peek() == '(' || fin.peek() == ')')
            {
                
                collections_of_input.push_back(std::stoi(reading_input));
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
                        pivot = std::stoi(reading_input);
                        reading_input.clear();
                    }
                }
                else if(ch == ')') // if the ch catch the real end of the line, then you will now proceed to find the tuple.
                {
                    partition_at(collections_of_input, pivot);
                    collections_of_input.clear();
                    break;
                }
            }
            
            
            
        }
        
    }
}

int main()
{
    std::string file_name = "/Users/gihyeonroh/Downloads/data_c.txt";
    read_input_from_file(file_name);
    
    return 0;
}
