public class LeetCode27 {
    public int removeElement(int[] a, int val) {
        int n = a.length;
        for (int i=0; i<n; ){
            if(a[i] == val){
                for(int j=i; j < n-1; j++)
                    a[j] = a[j+1];
                n--;
            }
            else i++; //khong phai xoa

        }
        return n;
    }
    public int removeElement2(int[] a, int val) {
        int k = 0;
        for (int i=0; i<a.length; i++){
           if(a[i]!= val){
               a[k] = a[i];
               k++;
           }
        }
        return k;
    }
    public void run(){
        int[] a = {3,2,2,3};
        System.out.println(removeElement(a,2));
    }
}
