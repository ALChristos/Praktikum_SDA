// Kompleksitas Waktu Analisis Program

#include <iostream>
using namespace std;

int FindMin(int A[], int n, int &idx_min) {
    int min = A[0];   
    idx_min = 0;
    
    for (int i = 1; i <= n - 1; i++) {  
        if (A[i] < min) {               
            min = A[i];
            idx_min = i;
        }
    }

    return min;  
}

int main() {
    int fibonaci[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;
    
    cout<<"Array Fibonacci: ";
    for (int i = 0; i < n; i++) {
        cout<<fibonaci[i]<<" ";
    }
    cout<<endl;
    
    int idx_min;
    int nilai_min = FindMin(fibonaci, n, idx_min);
    
    cout<<"\nNilai Minimum: "<<nilai_min<<endl;
    cout<<"Indeks: "<<idx_min<<endl;
    
    cout<<"\n=== Hasil Analisis ==="<<endl;
    cout<<"Tmin(8) = 2(8) + 1 = "<<(2*n + 1)<<" operasi -> O(n)"<<endl;
    cout<<"Tmax(8) = 3(8) = "<<(3*n)<<" operasi -> O(n)"<<endl;
    
    return 0;
}

// +-------------------------+------+------------+-------------+
// | Pseudocode              | Cost | Best Case  | Worst Case  |
// +-------------------------+------+------------+-------------+
// | min <- A[0]             |  c1  |     1      |      1      |
// | for i <- 1 to n-1       |  c2  |     n      |      n      |
// | if A[i] < min           |  c3  |    n-1     |     n-1     |
// | min <- A[i]             |  c4  |     0      |     n-1     |
// | return min              |  c5  |     1      |      1      |
// +-------------------------+------+------------+-------------+

// Tmin(n) = 1 + n + (n-1) + 0 + 1 = 2n + 1
// Tmin(8) = 2(8) + 1 = 17 operasi
// Best Case terjadi ketika nilai minimum ada di A[0]
// sehingga baris "min <- A[i]" tidak pernah dijalankan
// Big-O Best Case  = O(n)
// Tmax(n) = 1 + n + (n-1) + (n-1) + 1 = 3n
// Tmax(8) = 3(8) = 24 operasi
// Worst Case terjadi ketika array terurut menurun
// sehingga "min <- A[i]" dijalankan setiap iterasi
// Big-O Worst Case = O(n)