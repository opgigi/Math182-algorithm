#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

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

std::vector<int> medians_of_quintets(std::vector<int> target_vector)
{
    int left = 0;
    int right = 0;
    int number_of_subarray = 0;
    std::vector<int> midian_of_quintets;
    
    if(target_vector.size() % 5 == 0)
    {
        number_of_subarray = target_vector.size() / 5;
    }
    else
    {
        number_of_subarray = (target_vector.size() /5) + 1;
    }
    
    // once you find the number of the total possible subarray, then now you will break it down to the pieces.
    
    
    // this is the formula that you push back the
    for(int i = 0; i < number_of_subarray - 1; ++i)
    {
        left = right;
        right = 5 + 5*i;
        
        midian_of_quintets.push_back(medians_of_few(target_vector, left, right));
    }
    
    left = right;
    right = target_vector.size();
    
    midian_of_quintets.push_back(medians_of_few(target_vector, left, right));
    
    
    return midian_of_quintets;
    
}

std::vector<int> partition_at(std::vector<int> collections_of_input, int pivot, int& i_th_smallest)
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
    
    // after you breaking into two partition you need to tell what partition to return and update the i_th smallest.
    
    // if the partition left size is bigger than i_th smallest, that means it's one of the element on the left side.
    if(partition_left.size() > i_th_smallest)
    {
        
        return partition_left;
    }
    else // else if the partition left size is smaller than the size of the left partition, then the i_th smallest will be located on the right side.
    {
        i_th_smallest = i_th_smallest - partition_left.size();
    }
    
    return partition_right;
    
    
}

void quickselect(std::vector<int> target_vector, int length_of_array, int i_th_smallest, int &the_actual_value, bool is_left)
{
    
    int median_of_median = 0;
    std::vector<int> collections_of_median;
    std::vector<int> partitioned_array;
    int i_th_smallest_copy = i_th_smallest;
    

    
    if(target_vector.size() == 1)
    {
        the_actual_value = target_vector[0];
    }
    else
    {
        /*
         Otherwise, find the median m of medians_of_quintets(A) by recursively calling quickselect, and run partition_at on A and m to get (A<, A>). If A< is long enough so that the desired element is in A<, recursively call quickselect on A< with the appropriate index.
         If A> is long enough so that the desired element is in A>, recursively call quickselect on A> with the appropriate index. Otherwise, m is the desired element, so return m.
         */
        
        // break the array into groups of 5, we we will sort each group, and then store all the median possible element in the collections of median.
        collections_of_median = medians_of_quintets(target_vector);
        
        
        
        // after this process, you have the median of quintets of target array. then you will try to find the median_of_median using the medians_of_few function.
        
        // then we will recursively compute the median of colletions of median.
        while(collections_of_median.size() > 1)
        {
            collections_of_median = medians_of_quintets(collections_of_median);
        }
        
        median_of_median = collections_of_median[0];
        
        
        // now we need to partition of target vector around median_of_median;
        partitioned_array = partition_at(target_vector, median_of_median, i_th_smallest_copy);
        
        // now once you get the median_of_median, that would be your pivot and try to do the partitioning process.
        
        quickselect(partitioned_array, partitioned_array.size(), i_th_smallest_copy, the_actual_value, is_left);
        
    }
    
    
    
}

void read_input_from_file(std::string file_name)
{
    std::string reading_input;
    std::vector<int> collections_of_input;
    int i_th_smallest = 0;
    int the_actual_value = 0;
    
    

    
    
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
                        i_th_smallest = std::stoi(reading_input);
                        reading_input.clear();
                    }
                }
                else if(ch == ')') // if the ch catch the real end of the line, then you will now proceed to find the tuple.
                {
                    
                    
                    
                    quickselect(collections_of_input, collections_of_input.size(), i_th_smallest, the_actual_value);
                    collections_of_input.clear();
                    
                    std::cout << " " <<the_actual_value << '\n';
                    break;
                }
            }
            
            
            
        }
        
    }
}

int main()
{
    std::string file_name = "/Users/gihyeonroh/Downloads/data_d.txt";
    read_input_from_file(file_name);
    
    return 0;
}





