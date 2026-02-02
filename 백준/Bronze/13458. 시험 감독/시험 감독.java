import java.util.*;
import java.io.*;

public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        st = new StringTokenizer(br.readLine());
        Long n = Long.parseLong(st.nextToken());
        List<Long> list = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for(long i = 0;i<n;i++){
            list.add(Long.parseLong(st.nextToken()));
        }
        st = new StringTokenizer(br.readLine());
        Long b = Long.parseLong(st.nextToken());
        Long c = Long.parseLong(st.nextToken());

        Long total = n;
        for(int i=0;i<n;i++){
            if(list.get(i)-b<=0) continue;
            else{
                if((list.get(i)-b)%c==0){
                    total += ((list.get(i)-b)/c);
                }
                else{
                    total += (((list.get(i)-b)/c) + 1);
                }
            }
        }
        sb.append(total);
        System.out.println(sb);

    }
}
