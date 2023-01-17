#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <fstream>

/*
 Write an O(n) implementation of the function medians_of_quintets, which takes in
 an integer array A, and returns an array consisting of the median of the first five entries, followed by the median of the next five entries, followed by the median of the next five entries, and so on (the last median might be the median of less than five entries). Calculate all medians with median_of_few.
 
 Apply medians_of_quintets to each row of data_b.txt, and output each result as a row in
 submission_b.txt, as in the sample below
 */

int medians_of_few(std::vector<int> target_vector, int left, int right)
{
    std::sort(target_vector.begin() + left, target_vector.begin() + right);
    
    
    
    // if the size of the subarray has even number of element, then we have to take out the minimum value of the array.
    if((right - left) % 2 == 0)
    {
        target_vector.erase(target_vector.begin());
        
        return target_vector[left + (right - left) / 2];
    }
    
    return target_vector[left + (right - left) / 2];
        
}

void read_input_from_file(std::string file_name)
{
    std::string reading_input;
    int total_number_of_squares = 0;
    int total_number_of_element = 0;
    std::vector<int> collections_of_input;
    std::vector<int> collections_of_median;
    int left = 0;
    int right = 0;
    
    

    
    
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
                
                collections_of_input.push_back(std::stoi(reading_input));
                reading_input.clear();
            }
            
            
        }
        else if(ch == ']') // if the charactor is the next line, then we have to take the vector and break it into pieces at most five element in the subarray.
        {
            int number_of_subarray = 0;
            
            if(collections_of_input.size() % 5 == 0)
            {
                number_of_subarray = collections_of_input.size() / 5;
            }
            else
            {
                number_of_subarray = (collections_of_input.size() /5) + 1;
            }
            
            // once you find the number of the total possible subarray, then now you will break it down to the pieces.
            
            
            // this is the formula that you push back the
            for(int i = 0; i < number_of_subarray - 1; ++i)
            {
                left = right;
                right = 5 + 5*i;
                
                collections_of_median.push_back(medians_of_few(collections_of_input, left, right));
                
            }
            
            left = right;
            right = collections_of_input.size();
            
            collections_of_median.push_back(medians_of_few(collections_of_input, left, right));
            
            // now you need to print out all those collections of the median.
            std::cout << '[';
            
            for(int j = 0; j < collections_of_median.size() - 1; ++j)
            {
                std::cout << collections_of_median[j] << ',' << " ";
            }
            
            std::cout << collections_of_median[collections_of_median.size() - 1] << ']' << '\n';
            
            collections_of_median.clear();
            collections_of_input.clear();
            left = 0;
            right = 0;
        }
        
    }
    
    
    
    
    
}



int main()
{
    std::string file_name = "/Users/gihyeonroh/Downloads/data_b.txt";
    read_input_from_file(file_name);
    
    
    
    
    return 0;
}
