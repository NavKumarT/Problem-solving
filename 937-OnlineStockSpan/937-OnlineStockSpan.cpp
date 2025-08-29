// Last updated: 8/29/2025, 9:49:51 PM
class StockSpanner {
private: 
    vector<int> span;
    vector<int> prices;
    stack<int> st;
public:
    StockSpanner() {
     
    }
    
    int next(int price) {
        prices.push_back(price);
        if(span.size() == 0){
            span.push_back(1);
            st.push(0);
            return span.back();
        }
        if(price < prices[st.top()]){
            st.push(prices.size()-1);
            span.push_back(1);
        } else {
            while(st.empty() == false && price >= prices[st.top()]){
                st.pop();
            }
            if(st.empty()){
                span.push_back(prices.size());
                st.push(prices.size()-1);
            } else {
                span.push_back(prices.size() - 1 - st.top());
                st.push(prices.size()-1);
            }
        }
        return span.back();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */