import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] t = new int[n];
        int[] p = new int[n];
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            t[i] = Integer.parseInt(st.nextToken());
            p[i] = Integer.parseInt(st.nextToken());
        }
        int[] dp = new int[n+1];
        for(int i=0;i<n;i++){
            dp[i+1] = Math.max(dp[i+1], dp[i]);
            if(i+t[i]<=n){
                dp[i+t[i]] = Math.max(dp[i+t[i]],dp[i]+p[i]);
            }
        }

        System.out.print(dp[n]);
    }
}
