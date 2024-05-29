//solution 1 using another stack
// class MinStack {
// public:
//     stack<int>s;    // it will store min elemnets
//     stack<int>p;  // it will store history of min elements
//     MinStack() {
        
//     }
    
//     void push(int val) {    //s=> 2 5 8 1 4 5
//         p.push(val);        //p=> 2 2 2 1 1 1(min elements in stack s)
//         if(s.empty())
//         s.push(val);
//         else
//         s.push(min(val,s.top()));
//     }
    
//     void pop() {
//         p.pop();
//         s.pop();
//     }
    
//     int top() {
//         return p.top();
//     }
    
//     int getMin() {
//         return s.top();
//     }
// };






//solution 2=> Here we putting element then minimum element from stack 
// class MinStack {
// public:
// stack<int>s;
// int minEle;
//     MinStack() {
        
//     }
    
//     void push(int val) {   //input stack=> 8 9 2 3 1 5 
//         if(!s.empty())   // min elememts=> 8 8 2 2 1 1
//            minEle=min(s.top(),val);//input elem        ↓   ↓   ↓   ↓   ↓   ↓
//            else                               // s=> 8 8|9 8|2 2|3 2|1 1|5 1
//            minEle=val;            //min elements       ↑   ↑   ↑   ↑   ↑   ↑                 
           
//            s.push(val);           
//            s.push(minEle);
//     }
    
//     void pop() {
//            s.pop();
//            s.pop();
         
//     }
    
//     int top() {
//         int top_min=s.top();
//         s.pop();
//         int top=s.top();
//         s.push(top_min);
//         return top;
        
//     }
    
//     int getMin() {
//            return s.top();
//     }
// };









//solution 3 => 
//if we have to store two int values at single int space then we use modulo concept
// if we have to push element then we push diff elemnent which stores both
// 1 pushed element 2 min element in below stack  
// if pushed element=25 and min ele =2 => 25*100+2=2502
// we retreive pushed elements => 2502/100 & min element= 2502%100
// 100 is decided by range of elements
// class MinStack {
// public:
//     stack<int>s;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if(s.empty())
//         {
//             s.push(val*100+val);
//         }
//         else
//         s.push(val*100+min(val,s.top()%100));
//     }
    
//     void pop() {
//         s.pop();
//     }
    
//     int top() {
//         return (s.top()/100);
//     }
    
//     int getMin() {
//         return s.top()%100;
//     }
// };








//solutin 4
//https://www.youtube.com/live/1Fyc-2SNYO0?si=cNWPn7FDriL3ZpNJ
/*Time: O(1) space: O(n)
Cons: Integer overflow
Intuition: mn variable will always hold minimum value but if it doesn't, it means s.top contains flag, so before popping the stack top, update the min.

Algo:
While pushing
if x < mn : push 2*x-mn and put the provided x in mn
Similarly while popping
if s.top() < mn(indicates the flag): Restore the mn before popping: mn = 2* mn -s.top()*/
class MinStack {
public:
    stack<long>s;
    long  minEle;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty())
        {
            s.push(val);
            minEle=val;
        }
        else if(val<=minEle)
        {
            s.push(2ll*val-minEle);
            minEle=val;
        }
        else
        s.push(val);
    }
    
    void pop() {
        if(s.top()<minEle)
        {
            minEle=2*minEle-s.top();
        }
        s.pop();
    }
    
    int top() {
        if(s.top()<minEle)
        {
            return minEle;
        }
        return s.top();
    }
    
    int getMin() {
        return minEle;
    }
};
