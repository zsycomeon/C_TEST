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
        string info;  
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
	
	public : 
		Graph(int num) : iVertexNum(num) , iEdgeNum(0)
		{
			for(int i = 0; i<iVertexNum;++i)
			{
				char data[20]; 
				SVertexNode vnode;
				//node.info = data+str(i);
				sprintf(data , "vt_%d" , i);
				vnode.info = data;
				//
				vecVertex.push_back(vnode);
			}
		}	
		//生成一个边
		Edge makeEdge(int v, int w)
		{
			Edge edge;
			edge.iInitialNode = v;
			edge.iTerminalNode = w;
			++iEdgeNum;
			return edge;
		}
		//将一个边的末尾节点写入，首为节点的邻接点的
		void insertEdge(const Edge& e)
		{
			//只有vecVertex中存储的是节点，其他位置节点由int表示
			vecVertex.at(e.iInitialNode).vecLoc.push_back(e.iTerminalNode);
		}
		//打印每个顶点下的邻接点
		void showGraph()
		{
			for(int i = 0; i < iVertexNum; ++ i)
			{
				cout<<"("<<vecVertex.at(i).info<<")"<<endl;
				for(int j = 0;i<vecVertex.at(i).vecLoc.size(); ++j)
				{
					cout<<"->"<<"";
					cout<<vecVertex.at(vecVertex.at(i).vecLoc.at(j)).info<<endl;	
				}
			}
		}
		//深度优先遍历
		void dfs()
		{
			cout<<"depthFirstSearch :"<<endl;
			for(int i = 0;i<iVertexNum ; ++i)
			{
				vecVertex.at(i).bIsVisited = false;
				dfs(i);
			}
		}
		//对某个顶点的深度优先 
		//v vecVertex容器中的下标
		void dfs(int v)
		{
			int iAdjacent = 0;
			SVertexNode node;
			node = vecVertex.at(v);
			//操作遍历的顶点
			cout<<node.info<<endl;
			node.bIsVisited = true;
			for(int j = 0; j < node.vecLoc.size(); ++j)
			{
				iAdjacent =  node.vecLoc.at(j);  
				//从第一顶点的第一个顶点往下一直遍历
				if(!(vecVertex.at(iAdjacent).bIsVisited)) 
				{
					dfs(iAdjacent); 
				}					
					
			}
		}
		//广度优先遍历
		void wfs()
		{
			int count = 0;
			queue<int> bfs_queue;
			cout<<"widthFirstSearch:"<<endl;
			//置为未遍历
			for ( int i = 0; i < iVertexNum ; ++i )
			{
				vecVertex.at(i).bIsVisited = false;
			}
			for ( int i = 0; i < iVertexNum ; ++i)
			{
				if(!vecVertex.at(i).bIsVisited)
				{
					vecVertex.at(i).bIsVisited = true;
					cout<<vecVertex.at(i).info<<endl;
					
				}
				//遍历每个顶点的下的所有邻接点的下标
				bfs_queue.push(i);
				while(!bfs_queue.empty())
				{
					SVertexNode node = vecVertex.at(bfs_queue.front());
					bfs_queue.pop();
					for(int i = 0; i < node.vecLoc.size(); ++i)
					{
						//顶点的邻接点存储从零开始，存储的是顶点容器下的下标
						if(!vecVertex.at(node.vecLoc.at(i)).bIsVisited)
						{
							vecVertex.at(node.vecLoc.at(i)).bIsVisited = true;
							cout<<vecVertex.at(node.vecLoc.at(i)).info<<endl;
							//再存入每个邻接点
							bfs_queue.push(node.vecLoc.at(i));
							
						}
					}
				}
			}
				
		}
};
int main()
{
	//自动生成了5个顶点
	Graph graph(5);
	//将后面的节点填到前面节点的邻接点容器中
	graph.insertEdge(graph.makeEdge(0,1));
	graph.insertEdge(graph.makeEdge(0,2));
	graph.insertEdge(graph.makeEdge(1,2));
	graph.insertEdge(graph.makeEdge(3,4));
	graph.insertEdge(graph.makeEdge(3,2));
	graph.insertEdge(graph.makeEdge(0,1));
	return 0;
}
