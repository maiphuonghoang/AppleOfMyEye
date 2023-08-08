public class LeetCode88 {
    public void merge (int[] n1, int m, int[]n2, int n){
        for (int ai : n2) {
            chenPhanTuVaoMang(ai,n1,m);
            m++;
        }
        for (int ai : n1) {
            System.out.print(ai + " ");
        }
    }

    private void chenPhanTuVaoMang(int x, int[] a, int m) {
        boolean timDuocK = false;
        for (int k=0; k<m; k++){
            if(a[k]>x){
                timDuocK = true;
                for (int i = m-1; i>=k; i--){
                    a[i+1] = a[i];
                }
                a[k] = x;
                break;
            }
        }
        if(!timDuocK) a[m] = x;

    }

    public void merge2 (int[] n1, int m, int[]n2, int n){
        int i = m-1,j=n-1,k=m+n-1;
        while (k>=0){
            if(j<0){
                n1[k] = n1[i];
                i--;
            }
            else if(i<0){
                n1[k] = n2[j];
                j--;
            } else if (n1[i]>n2[j]) {
                n1[k] = n1[i];
                i--;
            }else{
                n1[k] = n2[j];
                j--;
            }
            k--;
        }
    }
    public void run(){
        int[] num1 = {2,3,4,5,0,0,0};
        int[] num2 = {3,0,6};
        merge(num1, 4, num2, 3);
    }
}
