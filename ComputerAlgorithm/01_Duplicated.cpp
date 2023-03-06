#include <iostream>
#include <cmath>

using namespace std;

long long getSum(long long num, long long num_size) {
    return (2*num+num_size-1)*num_size/2;
}
long long getPowSumFormula(long long num, long long num_size) {
    return num*(num+1)*(2*num+1)/6;
}
long long getPowSum(long long num, long long num_size) {
    long long total_sum = getPowSumFormula(num+num_size-1, num_size);
    long long part_sum = getPowSumFormula(num-1, num_size);
    return total_sum - part_sum;
}
long long calculateAnswer(long long a, long long b) {
    return (a + sqrt(2*b - a*a))/2;
}
void getAnswer(long long num_sum, long long pow_sum, long long min_value, long long num_size) {
    long long x_plus_y = num_sum - getSum(min_value, num_size);
    long long x_pow_plus_y_pow = pow_sum - getPowSum(min_value, num_size);
    long long answer_x = calculateAnswer(x_plus_y, x_pow_plus_y_pow);
    long long answer_y = x_plus_y - answer_x;

    cout << min(answer_x, answer_y) << endl << max(answer_x, answer_y);
}
void main_duplicated() {
    long long num_size, inp;
    long long num_sum=0, pow_sum=0, min_value=10000;
    cin >> num_size;
    for (long long i=0; i<num_size+2; i++){
        cin >> inp;
        num_sum += inp;
        pow_sum += inp*inp;
        min_value = min(min_value, inp);
    }
    getAnswer(num_sum, pow_sum, min_value, num_size);
}

int main() {
    main_duplicated();
    return 0;
}
