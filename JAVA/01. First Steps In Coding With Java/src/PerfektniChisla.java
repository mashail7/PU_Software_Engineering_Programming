public class PerfektniChisla {

    public static void main(String[] args) {
        for (int i = 2; i <= 1000; i++) {
            int total = 0;
            for (int j = 1; j < i; j++) {
                if (i % j == 0) {
                    total += j;
                }
            }
            if (total == i) {
                System.out.println(i);
            }
        }
    }
}
