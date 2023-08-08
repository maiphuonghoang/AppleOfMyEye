import java.util.ArrayList;

public class SwtSu23PE1 {
    public ArrayList<Integer> vicDiff(int [] ar1, int[] ar2){
        ArrayList<Integer> Output = null;
//        int[] ar1 = {};
        boolean found;
        if (ar1 != null && ar2 != null){
            Output = new ArrayList<Integer>();
            for(int item: ar1){
                int i = 0;
                found = false;
                System.out.println(found);
                while( i<= ar2. length && found == false){
                    if (item == ar2[i])
                        found = true;
                    i++;}
                if(found)
                    Output. add(item);
            }}
        return Output;
    }
}
