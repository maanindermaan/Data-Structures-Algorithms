// Jerome is an IT professional engineer. He has an old model configured chip in his house, which is not supported in his new laptop. He wants to re-configure it so that it can be used. To re-configure it, he has done many experiments. At last, finally he got a solution. The solution is, in the old chip there are two codes(numbers) written on it X and Y.
// He has to replace X with a new reconfigured code M. M must be the least number that must include X as the leading digits and it is a multiple of Y
// Can you help Jerome with a program that accepts X and Y and prints new reconfigured code M of the chip.
// Read the input from STDIN and print the output to STDOUT. Do not write arbitrary strings anywhere in the program, as these contribute to the standard output and test cases will fail.
// Constraints:
// i. X, Y >= 1
// Input Format:
// The input contains two codes X and Y of the old chip separated by a single white space.
// Output Format:
// The output must consist of new reconfigured code M of the chi
// Sample Input 1:
// 33 11
// Sample Output 1:
// 33
// Explanation 1:
// Old chip two codes, X and Y: 33 and 11.
// Here, by the following method of re-configuration, possibilities can be M: 33, 330, 331, 332, and so on.
// Here, considering M = 33, its leading digit(s) is X (33) and it is a multiple of Y(11).
// Hence, 33 is the new reconfigured code of the chip