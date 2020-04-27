## Recurrence Relation and Recursion

* Time Complexity of recursive function is equal to the number of calls to the function multiplied by total cost in one functional call.
* To compute the time complexity formulate a reccurence relation and solve it for $T(N) = f(N)$, where; $f(N)$ is a some function of N that doesn't depent on $T$. \
    **For Example:**\
    **1.** Linear Time
    ```c
    void myFunc(int n){
        if(n>0){
            cout<<n;
            myFunc(n-1);
        }
    }
    ```
    For the above function the recurrence relation can be formulated as; \
    $$T(N) = \begin{cases}
                1, & \text{$x=0$}\\
                T(N-1), & \text{$n>0$}
            \end{cases}$$ 
    By recursively putting value of $T(N-k)$, $T(N) \text{ comes to be N+1}$ so overall time complexity of the equation is $O(N)$.\
    **2.** $N^2$/Quadratic Time
    ```c
    void myFunc(int n){
        if(n>0){
            for(int i=0; i<n;i++>){
                cout<<n<<"\n";
            }
            myFunc(n-1);
        }
    }
    ```
    $$T(N) = \begin{cases}
            1, & n=0\\
            T(N-1) + N, & n>2
            \end{cases}$$
    
    $T(N) = \frac{N(N+1)}{2} + 1$ hence, Time complexity is $O(N^2)$\
    **3.** $nlog(n)$/logirthmic Time
    ```c
    void myFunc(int n){
        if(n>0){
            for(int i=0; i<n;i*=2>){
                cout<<n<<"\n";
            }
            myFunc(n-1);
        }
    }
    ```
    $$T(N) = \begin{cases}
            1, & n=0\\
            T(N-1) + log(N), & n>2
            \end{cases}$$
    
    $T(N) = log(N!)$ hence, Time complexity is $O(Nlog(N))$
