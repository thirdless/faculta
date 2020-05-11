import java.sql.*;

public class Main {
    public static void main(String[] args) {
        Connection c = null;
        Statement s = null;

        try{
            Class.forName("org.sqlite.JDBC");
            c = DriverManager.getConnection("jdbc:sqlite:paool10.db");
            c.setAutoCommit(false);
            s = c.createStatement();

            ResultSet rs = s.executeQuery("select * from Ranking");
            while(rs.next()){
                int may2019 = rs.getInt("May2019");
                int may2018 = rs.getInt("May2018");
                String change = rs.getString("Change");
                String lang = rs.getString("PrgLang");
                String rating = rs.getString("Ratings");
                System.out.println(may2019 + ", " + may2018 + ", " + change + ", " + lang + ", " + rating);
            }

            System.out.println("\n --- LIMBAJE AFLATE IN CRESTERE --- \n");
            rs = s.executeQuery("SELECT * FROM Ranking");
            while(rs.next()){
                int may2019 = rs.getInt("May2019");
                int may2018 = rs.getInt("May2018");
                String change = rs.getString("Change");
                String lang = rs.getString("PrgLang");
                String rating = rs.getString("Ratings");
                if(change.charAt(0) == '+') System.out.println(may2019 + ", " + may2018 + ", " + change + ", " + lang + ", " + rating);
            }

            System.out.println("\n --- RATE IN ORDINE DESCRESCATOARE --- \n");
            rs = s.executeQuery("SELECT * FROM Ranking ORDER BY CAST(SUBSTR(\"Ratings\", 1, LENGTH(\"Rating\") - 1) AS FLOAT) DESC;");
            while(rs.next()){
                int may2019 = rs.getInt("May2019");
                int may2018 = rs.getInt("May2018");
                String change = rs.getString("Change");
                String lang = rs.getString("PrgLang");
                String rating = rs.getString("Ratings");
                System.out.println(may2019 + ", " + may2018 + ", " + change + ", " + lang + ", " + rating);
            }

            rs.close();
            s.close();
            c.close();
        }
        catch(Exception e){
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            System.exit(0);
        }
    }
}
