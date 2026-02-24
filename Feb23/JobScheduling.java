
import java.util.*;

public class JobScheduling {
    public ArrayList<Integer> jobSequencing(int[] deadline, int[] profit) {
        int n = deadline.length;
        ArrayList<int[]> jobs = new ArrayList<>();
        for(int i=0; i<n; i++) {
            jobs.add(new int[]{deadline[i], profit[i]});
        }

        Collections.sort(jobs, (a, b) -> a[0]-b[0]);

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int ans = 0;
        for(int i=0; i<n; i++) {
            int time = jobs.get(i)[0];
            int p = jobs.get(i)[1];
            
            if(pq.size() < time) {
                pq.add(p);
                ans += p;
            } else if (pq.peek() < p) {
                ans -= pq.poll();
                pq.add(p);
                ans += p;
            }
        }

        return new ArrayList<>(Arrays.asList(pq.size(), ans));
    }
}
