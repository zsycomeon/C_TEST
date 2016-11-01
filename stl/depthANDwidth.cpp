#include "iostream"  
#include "vector"  
#include "queue"  
#include "string"  
using namespace std;  
#define Max 26  
  
class Graph  
{  
private:  
    struct SVertexNode   //节点信息  
    {  
        bool bIsVisited;  
        string data;  
        vector<int> vecLoc; //弧的令一个节点的存储  
        SVertexNode():bIsVisited(false)  
        {}  
    };  
  
    typedef struct SEdge  //边界信息  
    {  
        int iInitialNode;  
  
        int iTerminalNode;  
    }Edge;  
      
    int iVertexNum;        //顶点数目   
    int iEdgeNum;          //边数目  
    vector<SVertexNode> vecVertex;  //存储顶点的容器  
  
public:  
    /* 
    *  brief       Initalize the graph. 
    *     
    *          v: vertex number of the graph. 
    */  
    Graph(int v):iVertexNum(v), iEdgeNum(0)   //初始化  
    {  
        char szData[6];  
        SVertexNode node;  
  
        for(int i = 0; i < v; i++)  
        {  
            //节点info
			sprintf(szData, "v%d", i+1);  
            node.data = szData;      //有几个节点的话先进性分配 
			//i是节点编号			
            vecVertex.push_back(node);  
        }  
    }  
      
    /* 
    *  brief      Make an edge by initial node and terminal node. 
    */  
    Edge MakeEdge(int v, int w)  
    {  
        Edge edge;  
        //
		edge.iInitialNode = v;  
        edge.iTerminalNode = w;  
        iEdgeNum++;  
  
        return edge;  
    }  
  
    /* 
    *  brief      Insert an edge to the graph 
    */  
    void InsetEdge(const Edge &e)  
    {  
        vecVertex.at(e.iInitialNode).vecLoc.push_back(e.iTerminalNode);  
          
        //if the graph is Undigraph, need do something here...  
        //vecVertex.at(e.iTerminalNode).vecLoc.push_back(e.iInitialNode);  
  
        iEdgeNum++;  
    }  
  
    /* 
    *  brief       Show the graph. 
    */      
    void ShowGraph()  
    {  
        cout << "Show the graph" << endl;  
  
        for(int i = 0; i < iVertexNum; i++)  
        {  
            cout << "Node " << i << "(" << vecVertex.at(i).data << ")";  
              
            for(int j = 0; j < vecVertex.at(i).vecLoc.size(); j++)  
            {  
                cout << "->" << vecVertex.at(i).vecLoc.at(j);  
            }  
            cout << endl;  
        }  
    }  
  
    /* 
    *  brief       depth first search 
    */  
    void depthFirstSearch()  
    {  
        cout << "depthFirstSearch: " << endl;  
        for(int i = 0; i < iVertexNum; i++)  
        {  
            if(!vecVertex.at(i).bIsVisited)  
            {  
                depthFirstSearch(i);  
            }  
        }  
    }  
	//对同一节点的递归
    void depthFirstSearch(int v)  
    {  
        int iAdjacent = 0;  
        SVertexNode node = vecVertex.at(v);  
  
        vecVertex.at(v).bIsVisited = true;  
        cout << node.data << endl;   
        //thus we can search the node  
        for(int i = 0; i < node.vecLoc.size(); i++)  
        {  
            iAdjacent =  node.vecLoc.at(i);  
  
            if(!(vecVertex.at(iAdjacent).bIsVisited))  
                depthFirstSearch(iAdjacent);  
        }  
    }  
  
    /* 
    *  brief     bread first search with the unjoin sort， use a queue make the search simple 
    */  
  
    //问题：横向循环问题。  
    void breadFirstSearch()  
    {  
        int count = 0;  
        queue<int> bfs_queue;  
  
        cout << "breadFirstSearch: " << endl;  
        for(int i = 0; i < iVertexNum; i++)  
        {  
            vecVertex.at(i).bIsVisited = false;  
        }  
        for(int i = 0; i < iVertexNum; i++)  
        {  
            if(!(vecVertex.at(i).bIsVisited))  
            {  
                vecVertex.at(i).bIsVisited = true;  
                cout << vecVertex.at(i).data << endl;  
            }  
            bfs_queue.push(i);  
  
            while(!bfs_queue.empty())    //利用了一个队列很巧妙的实现了。  
            {  
                SVertexNode node = vecVertex.at(bfs_queue.front());  
                bfs_queue.pop();  
                for(int i = 0; i < node.vecLoc.size(); i++)  
                    if(!(vecVertex.at(node.vecLoc.at(i)).bIsVisited))  
                    {  
                        vecVertex.at(node.vecLoc.at(i)).bIsVisited = true;  
                        cout << vecVertex.at(node.vecLoc.at(i)).data << endl;  
                        bfs_queue.push(node.vecLoc.at(i));  
                    } // end if  
            } // end while  
  
        } // end for  
    } // end breadFirstSearch  
  
}; //class Graph  
  
/* 
*  brief    main for test the class of Graph and use the depthFirstSearch to search 
*/  
int main()  
{  
    Graph graph(4);  
    graph.InsetEdge(graph.MakeEdge(0, 3));  
    graph.InsetEdge(graph.MakeEdge(0, 2));  
    graph.InsetEdge(graph.MakeEdge(1, 0));  
    graph.InsetEdge(graph.MakeEdge(3, 1));  
    //graph.InsetEdge(graph.MakeEdge(3, 0));  
  
    graph.ShowGraph();  
  
    graph.depthFirstSearch();  
  
    graph.breadFirstSearch();  
  
    cin.get();  
    cin.get();  
    return 0;  
}  
