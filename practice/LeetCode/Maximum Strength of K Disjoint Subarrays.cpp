// https://leetcode.com/problems/maximum-strength-of-k-disjoint-subarrays/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */

let mem;

const maximumStrengthRecursion = (arr, k, start = 0, maximize = true) => {
    const n = arr.length - start;
    if (start === 0) {
        mem = Array.from({ length: k + 1 }, () => Array(n + 1));
    }
    if (mem[k][start] !== undefined) {
        return mem[k][start];
    }
    if (k > n) {
        return maximize ? -Infinity : Infinity;
    }
    if (k === 0) {
        return 0;
    }
    if (n === 1) {
        return arr[start];
    }
    let sum = 0, ans = maximize ? -Infinity : Infinity;
    for (let s = start; s < arr.length; s++) {
        sum = 0;
        for (let i = s; i < arr.length; i++) {
            sum = sum + arr[i];
            const subProblem = maximumStrengthRecursion(arr, k - 1, i + 1, !maximize);
            ans = maximize
                ? Math.max(ans, sum * k - subProblem)
                : Math.min(ans, sum * k - subProblem);

        }
    }
    return mem[k][start] = ans;
};

const maximumStrengthRecuImprov = (arr, k, start = 0, maximize = true) => {
    const n = arr.length - start;
    if (start === 0) {
        mem = Array.from({ length: k + 1 }, () => Array(n + 1));
    }
    if (mem[k][start] !== undefined) {
        return mem[k][start];
    }
    if (k > n) {
        return maximize ? -Infinity : Infinity;
    }
    if (k === 0) {
        return 0;
    }
    if (n === 1) {
        return arr[start];
    }
    let sum = 0, ans = maximize ? -Infinity : Infinity;
    for (let i = start; i < arr.length; i++) {
        if (maximize ? sum < 0 : sum > 0) {
            sum = 0;
        }
        sum = sum + arr[i];
        const subProblem = maximumStrengthRecuImprov(arr, k - 1, i + 1, !maximize);
        ans = maximize
            ? Math.max(ans, sum * k - subProblem)
            : Math.min(ans, sum * k - subProblem);

    }
    return mem[k][start] = ans;
};

const maximumStrengthDP = (arr, K) => {
    const N = arr.length;
    const dpMx = Array.from({ length: K + 1 }, () => Array(N + 1).fill(-Infinity));
    const dpMn = Array.from({ length: K + 1 }, () => Array(N + 1).fill(Infinity));
    dpMx[0] = Array(N + 1).fill(0);
    dpMn[0] = Array(N + 1).fill(0);

    // sum = [j....n]
    // dpMx[k][n] = max(dpMx[k][n], k * sum - dpMn[k - 1][j - 1])
    // dpMn[k][n] = min(dpMn[k][n], k * sum - dpMx[k - 1][j - 1])
    for (let k = 1; k <= K; k++) {
        let weight = K - k + 1;
        for (let n = 1; n <= N; n++) {
            let sum = 0;
            for (let j = n - 1; j >= 0; j--) {
                sum = sum + arr[j];
                dpMx[k][n] = Math.max(dpMx[k][n], weight * sum - dpMn[k - 1][j])
                dpMn[k][n] = Math.min(dpMn[k][n], weight * sum - dpMx[k - 1][j])
            }
            // to account for solution where all subarray ended befor taking n
            dpMx[k][n] = Math.max(dpMx[k][n], dpMx[k][n - 1]); 
            dpMn[k][n] = Math.min(dpMn[k][n], dpMn[k][n - 1]);
        }
    }
    return dpMx[K][N];
};

const maximumStrengthDPOptimised = (arr, K) => {
    const N = arr.length;
    const prefixSum = Array(N + 1).fill(0);
    prefixSum[0] = 0;
    for (let i = 1; i <= N; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }
    const dpMx = Array.from({ length: K + 1 }, () => Array(N + 1).fill(-Infinity));
    const dpMn = Array.from({ length: K + 1 }, () => Array(N + 1).fill(Infinity));
    dpMx[0] = Array(N + 1).fill(0);
    dpMn[0] = Array(N + 1).fill(0);

    // for (let k = 1; k <= K; k++) {
    //     let weight = K - k + 1;
    //     for (let n = 1; n <= N; n++) {
    //         for (let j = n - 1; j >= 0; j--) {
    //             // let sum = prefixSum[n] - prefixSum[j];
    //             // dpMx[k][n] = Math.max(dpMx[k][n], weight * sum - dpMn[k - 1][j]);
    //             // dpMn[k][n] = Math.min(dpMn[k][n], weight * sum - dpMx[k - 1][j]);

    //             // dpMx[k][n] = Math.max(dpMx[k][n], weight * (prefixSum[n] - prefixSum[j]) - dpMn[k - 1][j]);
    //             // dpMn[k][n] = Math.min(dpMn[k][n], weight * (prefixSum[n] - prefixSum[j]) - dpMx[k - 1][j]);

    //             dpMx[k][n] = Math.max(dpMx[k][n], weight * prefixSum[n] - weight * prefixSum[j] - dpMn[k - 1][j]);
    //             dpMn[k][n] = Math.min(dpMn[k][n], weight * prefixSum[n] - weight * prefixSum[j] - dpMx[k - 1][j]);
    //         }
    //         // to account for solution where all subarray ended befor taking n
    //         dpMx[k][n] = Math.max(dpMx[k][n], dpMx[k][n - 1]); 
    //         dpMn[k][n] = Math.min(dpMn[k][n], dpMn[k][n - 1]);
    //     }
    // }

    // for (let k = 1; k <= K; k++) {
    //     let weight = K - k + 1;
    //     for (let n = 1; n <= N; n++) {
    //         let maxMx = -Infinity, minMn = Infinity;
    //         // We are calc, max/min again and again, whereas we can use previous result
    //         for (let j = n - 1; j >= 0; j--) {
    //             maxMx = Math.max(maxMx, - weight * prefixSum[j] - dpMn[k - 1][j]);
    //             minMn = Math.min(minMn, - weight * prefixSum[j] - dpMx[k - 1][j]);
    //         }
    //         dpMx[k][n] = weight * prefixSum[n] + maxMx; 
    //         dpMn[k][n] = weight * prefixSum[n] + minMn;
    //         // to account for solution where all subarray ended befor taking n
    //         dpMx[k][n] = Math.max(dpMx[k][n], dpMx[k][n - 1]); 
    //         dpMn[k][n] = Math.min(dpMn[k][n], dpMn[k][n - 1]);
    //     }
    // }

    for (let k = 1; k <= K; k++) {
        let weight = K - k + 1;
        let maxMx = -Infinity, minMn = Infinity;
        for (let n = 1; n <= N; n++) {
            maxMx = Math.max(maxMx, - weight * prefixSum[n - 1] - dpMn[k - 1][n - 1]);
            minMn = Math.min(minMn, - weight * prefixSum[n - 1] - dpMx[k - 1][n - 1]);
            dpMx[k][n] = weight * prefixSum[n] + maxMx; 
            dpMn[k][n] = weight * prefixSum[n] + minMn;
            // to account for solution where all subarray ended befor taking n
            dpMx[k][n] = Math.max(dpMx[k][n], dpMx[k][n - 1]); 
            dpMn[k][n] = Math.min(dpMn[k][n], dpMn[k][n - 1]);
        }
    }

    return dpMx[K][N];
};

// const maximumStrength = maximumStrengthRecursion;
// const maximumStrength = maximumStrengthRecuImprov;
// const maximumStrength = maximumStrengthDP;
const maximumStrength = maximumStrengthDPOptimised;
