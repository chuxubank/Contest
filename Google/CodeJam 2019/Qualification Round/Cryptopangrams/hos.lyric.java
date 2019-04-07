import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;
import java.io.*;

public class Solution {
	public static void main(String[] args) {
		new Solution().run();
	}

	Scanner in = new Scanner(System.in);

	void _err(Object... os) {
		System.err.println(deepToString(os));
	}

	void run() {
		int numCases = in.nextInt();
		for (int caseId = 1; caseId <= numCases; ++caseId) {
			System.err.println("==== Case #" + caseId + " ====");

			BigInteger N = in.nextBigInteger();
			int L = in.nextInt();
			BigInteger[] A = new BigInteger[L];
			for (int i = 0; i < L; ++i) {
				A[i] = in.nextBigInteger();
			}
			// _err(N,L,A);

			BigInteger[] ps = new BigInteger[L + 1];
			for (int i = 1; i <= L - 1; ++i) {
				BigInteger g = A[i - 1].gcd(A[i]);
				if (g.compareTo(A[i - 1]) < 0 && g.compareTo(A[i]) < 0) {
					ps[i] = g;
					for (int j = i - 1; j >= 0; --j) {
						ps[j] = A[j].divide(ps[j + 1]);
					}
					for (int j = i + 1; j <= L; ++j) {
						ps[j] = A[j - 1].divide(ps[j - 1]);
					}
					break;
				}
			}
			// _err(ps);
			BigInteger[] qs = ps.clone();
			sort(qs);
			// _err(qs);
			Map<BigInteger, Integer> hs = new TreeMap<BigInteger, Integer>();
			int l = 0;
			for (BigInteger q : qs) {
				if (!hs.containsKey(q)) {
					hs.put(q, l++);
				}
			}

			char[] ans = new char[L + 1];
			for (int i = 0; i <= L; ++i) {
				ans[i] = (char) ('A' + hs.get(ps[i]));
			}

			System.out.println("Case #" + caseId + ": " + new String(ans));
			System.out.flush();
		}
	}
}
