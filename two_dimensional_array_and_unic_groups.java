import java.util.Arrays;
import java.util.HashSet;
//best, OlegTim; int nums >-1
public class Port {

    public static void main(String[] args) {
        String []    indexes = {"1,3-5", "2", "3-4"};
Object Port = new Object();
Port  = indexes;

        int[][] indexes2 =numbers((String[]) Port);
        int[][] indexes3 =numbers2(indexes2);

   // test output start
        System.out.println("Последовательность чисел:");
        for (int j2 = 0; j2 < indexes2.length; j2++) {
            for (int j = 0; j < indexes2[j2].length; j++) {
                System.out.print(indexes2[j2][j] + "\t");
            }
            System.out.println();
        }
        System.out.println("Комбинации:");
        for (int j21 = 0; j21 < indexes3.length; j21++) {
            for (int j1 = 0; j1 < indexes3[j21].length; j1++) {
                System.out.print(indexes3[j21][j1] + " ");
            }
            System.out.print("\t");
        }
        // test output end
}
public static int[][] numbers(String[] indexes)
    {
        int [][] arr = new int[indexes.length][];
        for (int i = 0; i < indexes.length; i++) {
            HashSet<Integer> lineset = new HashSet<Integer>();
            String s = indexes[i];
            String []  line    = s.split(",");

            for (int i2 = 0; i2 < line.length; i2++) {
                String s2=line[i2];
            if (s2.contains("-")) {
                String []  line2    = s2.split("-");
                int z1=0;  int z2=0;
                try{ z1 = Integer.parseInt(line2[0]);
                    z2 = Integer.parseInt(line2[1]);
                }catch(Exception e){System.out.println(e);}
                int dif = Math.abs(z2)-Math.abs(z1);
                for (int i3 = 0; i3 <= dif; i3++) {
                    int z = z1++;
                    try{lineset.add(z);}catch(Exception e){System.out.println(e);}
                }
            }
            else{
                int z=0;
                try{ z = Integer.parseInt(s2);}catch(Exception e){System.out.println(e);}
                try{lineset.add(z);}catch(Exception e){System.out.println(e);}
            }
        }
            Integer[] linearr = lineset.toArray(new Integer[0]);
            Arrays.sort(linearr);
            int[] linearr2 = Arrays.stream(linearr).mapToInt(Integer::intValue).toArray();
               arr[i]=  linearr2;
        }
        return arr;
    }//numbers() end
    public static int[][] numbers2(int[][] indexes2){
        int z = indexes2.length;
        int combmun=1; int counter=0;
        int [] ar = new int[z];
        int [] ar2 = new int[z];
        for (int i = 0; i < z; i++) {
            int z2 = indexes2[i].length;
            ar2[i]=z2-1;
            combmun = combmun*z2;
        }
        int [][] arr = new int[combmun][z];

        for (int w = 0; w < combmun; w++) {
            for (int w2 = 0; w2 <z; w2++) {
                int zeta = ar[w2];
                zeta = zeta+counter;
                if (zeta>ar2[w2]){
                    ar[w2]=0;
                    counter=1;
                }
                else{
                    ar[w2]=zeta;
                    counter=0;
                }
            }
            for (int w2 = 0; w2 <z; w2++) {
                int u = indexes2[w2][ar[w2]];
                arr[w][w2]=u;
            }
            counter=1;
        }
        return arr;
    }
}
