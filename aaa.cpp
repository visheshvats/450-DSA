#include<iostream>
#include<vector>
using namespace std;

bool isPrime(int n)
{
    
    if (n <= 1)
        return false;
 
    
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
 

vector<int> calculatePrimeNumber(int num)
{
    vector<int> answer;
    for (int i = 2; i <= num; i++){
        if (isPrime(i))
            answer.push_back(i);
    }

    return answer;
}
 