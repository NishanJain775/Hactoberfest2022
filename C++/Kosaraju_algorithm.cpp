//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void dfs(int src, vector<int> &vis, stack<int> &st, vector<int> adj[])
    {
        vis[src]=1;
        
        for(auto x:adj[src])
        {
            if(!vis[x])
            {
                dfs(x,vis,st,adj);
            }
        }
        st.push(src);
    }
    void revdfs(int src, vector<int> &vis, vector<int> adj[])
    {
        vis[src]=1;
        for(auto x:adj[src])
        {
            if(!vis[x])revdfs(x,vis,adj);
        }
    }
    
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,st,adj);
            }
        }
        
        vector<int> tr[V];
        for(int i=0;i<V;i++)
        {
            vis[i]=0;
            for(auto x:adj[i])
            {
                tr[x].push_back(i);
            }
        }
        
        int res=0;
        while(st.size())
        {
            int node=st.top();
            st.pop();
            if(!vis[node])
            {
                res++;
                revdfs(node,vis,tr);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
