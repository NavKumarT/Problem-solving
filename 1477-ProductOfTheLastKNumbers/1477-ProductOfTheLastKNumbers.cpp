// Last updated: 8/29/2025, 9:49:10 PM
class ProductOfNumbers {
private: 
    vector<int> multiple;
    int size = 0;
public:
    ProductOfNumbers() {
        multiple.push_back(1);
    }
    
    void add(int num) {
        if(num == 0){
           multiple = {1};
           size = 0;
        }
       else {
         multiple.push_back(multiple[size] * num);    
        size++; 
       }   
    }
    
    int getProduct(int k) {
        if(k > size)
            return 0;
        return multiple[size] / multiple[size-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */