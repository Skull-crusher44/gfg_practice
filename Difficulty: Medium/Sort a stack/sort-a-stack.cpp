/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack ::sort() {
    
    stack<int>temp;
    while(!s.empty()){
        int tempele = s.top();
        s.pop();
        
        // push in sorted temp stack
        while(!temp.empty()&&tempele>temp.top()){
            s.push(temp.top());
            temp.pop();
        }
        temp.push(tempele);
    }
    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }
    
    
}