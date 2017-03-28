class TwoSum {
public:
    /** Initialize your data structure here. */

    /** Add the number to an internal data structure.. */
    void add(int number) {
        if(ht.find(number) != ht.end()){
            ht[number]++;
        }
        else{
            ht[number] = 1;
        }
        ar.push_back(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto& i : ar){
            int num1 = i;
            int num2 = value - num1;
            /* there exists two cases:
            1: two same number adds up to the value
            2: two different number adds up to the value
            */
            if((num1 == num2 && ht[num1] > 1) || (num1 != num2 && ht.find(num2) != ht.end()))
            return true;
        }
        return false;
    }
private:
    // save all the numbers
    vector<int> ar;
    // this map records how many times the number has appeared
    unordered_map<int, int> ht;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */