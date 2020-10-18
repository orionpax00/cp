int mod(string t, int N) { 
    int rem = 0;
    for (int i = 0; i < t.length(); i++) { 
        rem = rem * 10 + (t[i] - '0');
        rem = rem % N;
    } 
    return rem;
}
