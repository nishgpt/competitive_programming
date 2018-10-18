import java.io.*;
class abc
{
    public static void main(String args[])throws IOException
    {
        String s,p,q;int a[]=new int[550];
        int i,j,c,l;
        BufferedReader cin=new BufferedReader(new InputStreamReader(System.in));
        s=cin.readLine();
        for( ;s.charAt(0)!='*'; )
        {for(i=0;i<550;i++)a[i]=0;c=0;
            p=s.substring(0,s.indexOf(' '));
            q=s.substring(s.indexOf(' ')+1);
            l=p.length();
            for(i=0;i<l;i++)
            {
                if(p.charAt(i)==q.charAt(i))
                a[i]=0;
                else a[i]=1;
            }
            for(i=0;i<l;i++)
            {
                if(a[i]==1&&a[i+1]==0)
                c++;
            }
            System.out.println(c);
            s=cin.readLine();
        }
    }
}