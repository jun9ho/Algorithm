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
        List<Integer> list = new ArrayList<>();
        for(int i = 0;i<n;i++){
            list.add(Integer.parseInt(st.nextToken()));
        }
        st = new StringTokenizer(br.readLine());
        int v = Integer.parseInt(st.nextToken());
        int cnt = 0;
        for(int e : list){
            if(e==v){
                cnt++;
            }
        }
        sb.append(cnt);
        System.out.print(sb);
    }
}
