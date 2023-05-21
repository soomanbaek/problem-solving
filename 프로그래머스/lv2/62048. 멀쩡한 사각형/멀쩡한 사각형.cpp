int GCD(int a, int b){
    if(b==0)
        return a;
    return GCD(b, a%b);
}

long long solution(int w,int h) {
    long long answer;
    long long gcd = GCD(w,h);
    answer = (long long)w*h - w - h + gcd;
    return answer;
}