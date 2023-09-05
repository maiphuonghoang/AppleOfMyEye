Giả sử cấu hình cần xây dựng có dạng X1,X2,...,XN  
### Mô hình thuật toán quay lui:  
Try(int i){  
    for (j = Khả năng 1; j <= Khả năng M; j++){  
        if(chấp nhận khả năng j){  
            X[i] = khả năng j  
            if(i == N)  
                Thông báo cấu hình tìm được  
            else  
                Try(i + 1)  
        }  
    }  
}  
### Xâu nhị phân có độ dài N 
Try(int i){  
    for (j = 0; j <= 1; j++){  
        X[i] = j;  
        if(i == N)  
            inKq();    
        else  
            Try(i + 1)  
    }  
}  
### Tổ hợp chập K của N
- Khả năng của i 
    + max = N - K + i
    + min = giá trị phần tử đứng trước cộng 1  
Try(int i){  
    for (j = X[i-1] + 1; j <= N - K + i; j++){  
        X[i] = j;  
        if(i == K)  
            inKq();    
        else  
            Try(i + 1)  
    }  
}  
### Hoán vị của N 
Try(int i){  
    for (j = 1; j <= N; j++){  
        if(j chưa được sử dụng){
            Đánh dấu used[j] = 1; 
            X[i] = j;  
            if(i == N)  
                inKq();    
            else  
                Try(i + 1)  
            Backtrack 
            used[j] = 0;
        }
    }  
} 