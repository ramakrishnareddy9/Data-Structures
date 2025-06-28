import java.util.Arrays;
import java.util.Scanner;

public class GolombsTrominoTiling {
    static int trominoId = 0;

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the grid size (must be a power of 2 and atleast 2) : ");
        int n = input.nextInt();
        System.out.print("Enter the dimensions of the empty tile : ");
        int emptyRow = input.nextInt();
        int emptyCol = input.nextInt();
        int[][] grid = new int[n][n];

        for (int[] row : grid) {
            Arrays.fill(row, 0);
        }
        grid[emptyRow][emptyCol] = -1;
        tile(grid, n, 0, 0, emptyRow, emptyCol);
        printGrid(grid);
        input.close();
    }

    static void tile(int[][] grid, int size, int startRow, int startCol, int emptyRow, int emptyCol) {
        if (size == 2) {
            trominoId++;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    if (startRow + i != emptyRow || startCol + j != emptyCol) {
                        grid[startRow + i][startCol + j] = trominoId;
                    }
                }
            }
            return;
        }

        trominoId++;
        int mid = size / 2;
        int topLeftEmpty = (emptyRow < startRow + mid && emptyCol < startCol + mid) ? 1 : 0;
        int topRightEmpty = (emptyRow < startRow + mid && emptyCol >= startCol + mid) ? 1 : 0;
        int bottomLeftEmpty = (emptyRow >= startRow + mid && emptyCol < startCol + mid) ? 1 : 0;
        int bottomRightEmpty = (emptyRow >= startRow + mid && emptyCol >= startCol + mid) ? 1 : 0;

        if (topLeftEmpty == 0)
            grid[startRow + mid - 1][startCol + mid - 1] = trominoId;
        if (topRightEmpty == 0)
            grid[startRow + mid - 1][startCol + mid] = trominoId;
        if (bottomLeftEmpty == 0)
            grid[startRow + mid][startCol + mid - 1] = trominoId;
        if (bottomRightEmpty == 0)
            grid[startRow + mid][startCol + mid] = trominoId;

        tile(grid, mid, startRow, startCol,
                topLeftEmpty == 1 ? emptyRow : startRow + mid - 1,
                topLeftEmpty == 1 ? emptyCol : startCol + mid - 1);
        tile(grid, mid, startRow, startCol + mid,
                topRightEmpty == 1 ? emptyRow : startRow + mid - 1,
                topRightEmpty == 1 ? emptyCol : startCol + mid);
        tile(grid, mid, startRow + mid, startCol,
                bottomLeftEmpty == 1 ? emptyRow : startRow + mid,
                bottomLeftEmpty == 1 ? emptyCol : startCol + mid - 1);
        tile(grid, mid, startRow + mid, startCol + mid,
                bottomRightEmpty == 1 ? emptyRow : startRow + mid,
                bottomRightEmpty == 1 ? emptyCol : startCol + mid);
    }

    static void printGrid(int[][] grid) {
        for (int[] row : grid) {
            for (int cell : row) {
                System.out.printf("%3d", cell);
            }
            System.out.println();
        }
    }
}
