import java.io.*;
class abc
{
    public static void main(String args[])throws IOException
    {
        BufferedReader cin=new BufferedReader(new InputStreamReader(System.in));
        String s;int i,j,l;int a[]=new int[1000000];int b[]=new int[1000000];
        s=cin.readLine();
        while(s.equals("0")==false)
        {
            l=s.length();
            for(i=0;i<l;i++)
            a[i]=Integer.parseInt(s.substring(i,i+1));j=a[0]*10+a[1];b[0]=1;
            for(i=1;i<l;i++)
            {
                j=a[i-1]*10+a[i];
                if(i==1)
                {if(j<=26){if(a[i]!=0)b[i]=b[i-1]+1;else if(a[i]==0){b[i]=b[i-1];}}
                else if(j>26){b[i]=b[i-1];}
                }
                else if(i!=1&&a[i-1]!=0)
                {
                    if(j<=26){if(a[i]!=0){b[i]=b[i-1]+b[i-2];}else if(a[i]==0){b[i]=b[i-2];}}
                    else if(j>26){b[i]=b[i-1];}
                }
                else if(i!=1&&a[i-1]==0)
                {
                    b[i]=b[i-1];
                }
        }
        System.out.println(b[l-1]);s=cin.readLine();
    }
}
}
