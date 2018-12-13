import java.io.*;
class abs
{
    public static void main(String args[])throws IOException
    {
        BufferedReader cin=new BufferedReader(new InputStreamReader(System.in));
        String s[]=new String[3];
        int i,j,k,m,l;int sp=(int)' ';int u=(int)'_';int or=(int)'|';
        while((s[0]=cin.readLine())!=null)
        {
            for(i=1;i<3;i++)s[i]=cin.readLine();
            l=s[0].length();
            for(i=0;i<l;i+=3)
            {
               if(s[0].charAt(i)==' '&&s[0].charAt(i+1)=='_'&&s[0].charAt(i+2)==' '&&s[1].charAt(i)=='|'&&s[1].charAt(i+1)==' '&&s[1].charAt(i+2)=='|'&&s[2].charAt(i)=='|'&&s[2].charAt(i+1)=='_'&&s[2].charAt(i+2)=='|')
               System.out.print("0");
               else if(s[0].charAt(i)==' '&&s[0].charAt(i+1)==' '&&s[0].charAt(i+2)==' '&&s[1].charAt(i)==' '&&s[1].charAt(i+1)==' '&&s[1].charAt(i+2)=='|'&&s[2].charAt(i)==' '&&s[2].charAt(i+1)==' '&&s[2].charAt(i+2)=='|')
               System.out.print("1");
               else if(s[0].charAt(i)==' '&&s[0].charAt(i+1)=='_'&&s[0].charAt(i+2)==' '&&s[1].charAt(i)==' '&&s[1].charAt(i+1)=='_'&&s[1].charAt(i+2)=='|'&&s[2].charAt(i)=='|'&&s[2].charAt(i+1)=='_'&&s[2].charAt(i+2)==' ')
               System.out.print("2");
               else if(s[0].charAt(i)==' '&&s[0].charAt(i+1)=='_'&&s[0].charAt(i+2)==' '&&s[1].charAt(i)==' '&&s[1].charAt(i+1)=='_'&&s[1].charAt(i+2)=='|'&&s[2].charAt(i)==' '&&s[2].charAt(i+1)=='_'&&s[2].charAt(i+2)=='|')
               System.out.print("3");
               else if(s[0].charAt(i)==' '&&s[0].charAt(i+1)==' '&&s[0].charAt(i+2)==' '&&s[1].charAt(i)=='|'&&s[1].charAt(i+1)=='_'&&s[1].charAt(i+2)=='|'&&s[2].charAt(i)==' '&&s[2].charAt(i+1)==' '&&s[2].charAt(i+2)=='|')
               System.out.print("4");
               else if(s[0].charAt(i)==' '&&s[0].charAt(i+1)=='_'&&s[0].charAt(i+2)==' '&&s[1].charAt(i)=='|'&&s[1].charAt(i+1)=='_'&&s[1].charAt(i+2)==' '&&s[2].charAt(i)==' '&&s[2].charAt(i+1)=='_'&&s[2].charAt(i+2)=='|')
               System.out.print("5");
               else if(s[0].charAt(i)==' '&&s[0].charAt(i+1)=='_'&&s[0].charAt(i+2)==' '&&s[1].charAt(i)=='|'&&s[1].charAt(i+1)=='_'&&s[1].charAt(i+2)==' '&&s[2].charAt(i)=='|'&&s[2].charAt(i+1)=='_'&&s[2].charAt(i+2)=='|')
               System.out.print("6");
               else if(s[0].charAt(i)==' '&&s[0].charAt(i+1)=='_'&&s[0].charAt(i+2)==' '&&s[1].charAt(i)==' '&&s[1].charAt(i+1)==' '&&s[1].charAt(i+2)=='|'&&s[2].charAt(i)==' '&&s[2].charAt(i+1)==' '&&s[2].charAt(i+2)=='|')
               System.out.print("7");
               else if(s[0].charAt(i)==' '&&s[0].charAt(i+1)=='_'&&s[0].charAt(i+2)==' '&&s[1].charAt(i)=='|'&&s[1].charAt(i+1)=='_'&&s[1].charAt(i+2)=='|'&&s[2].charAt(i)=='|'&&s[2].charAt(i+1)=='_'&&s[2].charAt(i+2)=='|')
               System.out.print("8");
               else if(s[0].charAt(i)==' '&&s[0].charAt(i+1)=='_'&&s[0].charAt(i+2)==' '&&s[1].charAt(i)=='|'&&s[1].charAt(i+1)=='_'&&s[1].charAt(i+2)=='|'&&s[2].charAt(i)==' '&&s[2].charAt(i+1)==' '&&s[2].charAt(i+2)=='|')
               System.out.print("9");
            }
            System.out.println();
        }
    }
}