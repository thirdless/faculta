import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.Scanner;

public class DataBase {
    private Connection c = null;
    private Statement s = null;
    private Scanner scanner = null;

    public DataBase(){
        scanner = new Scanner(System.in);
        try {
            Class.forName("org.sqlite.JDBC");
            c = DriverManager.getConnection("jdbc:sqlite:paool10.db");
            c.setAutoCommit(false);
            s = c.createStatement();
        }
        catch(Exception e){
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            System.exit(0);
        }
    }

    public void show(){
        try{
            ResultSet rs = s.executeQuery("SELECT ROWID, * FROM Ranking");
            while(rs.next()){
                int id = rs.getInt("ROWID");
                int may2019 = rs.getInt("May2019");
                int may2018 = rs.getInt("May2018");
                String change = rs.getString("Change");
                String lang = rs.getString("PrgLang");
                String rating = rs.getString("Ratings");
                System.out.println("Row " + id + ": " + may2019 + ", " + may2018 + ", " + change + ", " + lang + ", " + rating);
            }
            rs.close();
        }
        catch(Exception e){
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            System.exit(0);
        }
    }

    public void add(){
        System.out.print("May2019: ");
        int may2019 = Integer.parseInt(scanner.nextLine());
        System.out.print("May2018: ");
        int may2018 = Integer.parseInt(scanner.nextLine());
        System.out.print("Change: ");
        String change = scanner.nextLine();
        System.out.print("PrgLang: ");
        String lang = scanner.nextLine();
        System.out.print("Ratings: ");
        String rating = scanner.nextLine();
        try{
            String rs = "INSERT INTO Ranking (May2019, May2018, Change, PrgLang, Ratings) " +
                    "VALUES (" + may2019 + ", " + may2018 + ", \"" + change + "\", \"" + lang + "\", \"" + rating + "\" );";
            s.executeUpdate(rs);
            c.commit();
        }
        catch(Exception e){
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            System.exit(0);
        }
    }

    public void delete(){
        System.out.print("\n Row number to delete: ");
        int row = Integer.parseInt(scanner.nextLine());
        try{
            String rs = "DELETE FROM Ranking WHERE ROWID=" + row;
            s.executeUpdate(rs);
            c.commit();
        }
        catch(Exception e){
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            System.exit(0);
        }
    }

    public void change(){
        System.out.print("Row number: ");
        int row = Integer.parseInt(scanner.nextLine());
        System.out.print("May2019: ");
        int may2019 = Integer.parseInt(scanner.nextLine());
        System.out.print("May2018: ");
        int may2018 = Integer.parseInt(scanner.nextLine());
        System.out.print("Change: ");
        String change = scanner.nextLine();
        System.out.print("PrgLang: ");
        String lang = scanner.nextLine();
        System.out.print("Ratings: ");
        String rating = scanner.nextLine();
        try{
            String rs = "UPDATE Ranking SET May2019 = \"" + may2019 + "\", May2018 = " + may2018 + ", Change = \"" + change + "\", PrgLang = \"" + lang + "\", Ratings = \"" + rating + "\" WHERE ROWID=" + row;
            s.executeUpdate(rs);
            c.commit();
        }
        catch(Exception e){
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            System.exit(0);
        }
    }

    public void sort(){
        try{
            ResultSet rs = s.executeQuery("SELECT * FROM Ranking ORDER BY CAST(SUBSTR(\"Ratings\", 1, LENGTH(\"Rating\") - 1) AS FLOAT) DESC;");
            while(rs.next()){
                int may2019 = rs.getInt("May2019");
                int may2018 = rs.getInt("May2018");
                String change = rs.getString("Change");
                String lang = rs.getString("PrgLang");
                String rating = rs.getString("Ratings");
                System.out.println(may2019 + ", " + may2018 + ", " + change + ", " + lang + ", " + rating);
            }
            rs.close();
        }
        catch(Exception e){
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            System.exit(0);
        }
    }

    public void disc(){
        try{
            s.close();
            c.close();
        }
        catch(Exception e){
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            System.exit(0);
        }
    }
}
