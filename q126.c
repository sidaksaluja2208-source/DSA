/*You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

 

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation:



From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.

Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.

Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0

Output: [[0,0,0],[0,0,0]]

Explanation:

The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.

 

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n*/


#include <stdio.h>

#define MAX 50

void dfs(int image[MAX][MAX], int m, int n, int r, int c, int origColor, int newColor) {
    // Boundary check
    if (r < 0 || r >= m || c < 0 || c >= n)
        return;

    // Only process cells with original color
    if (image[r][c] != origColor)
        return;

    // Change color
    image[r][c] = newColor;

    // 4 directions
    dfs(image, m, n, r+1, c, origColor, newColor);
    dfs(image, m, n, r-1, c, origColor, newColor);
    dfs(image, m, n, r, c+1, origColor, newColor);
    dfs(image, m, n, r, c-1, origColor, newColor);
}

int main() {
    int m, n;
    int image[MAX][MAX];
    int sr, sc, color;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter image matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    printf("Enter starting row, column and new color: ");
    scanf("%d %d %d", &sr, &sc, &color);

    int origColor = image[sr][sc];

    // If same color, no need to process
    if (origColor != color) {
        dfs(image, m, n, sr, sc, origColor, color);
    }

    printf("Updated Image:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}