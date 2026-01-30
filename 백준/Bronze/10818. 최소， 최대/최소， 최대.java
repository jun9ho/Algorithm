import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int min = 1000001;
        int max = -1000001;
        for(int i =0;i<n;i++){
            int a = Integer.parseInt(st.nextToken());
            if(a<min) min =a;
            if(a>max) max =a;
        }
        sb.append(min).append(" ").append(max);

        System.out.print(sb);
    }
}
