class Node{
    
    public int v;
    public int w;

    Node(int node, int weight){
        this.v = node;
        this.w = weight;
    }
}

class Solution {
    public int[] dijkstra(int V, int[][] edges, int src) {
        // code here
        
        // node , dist
        PriorityQueue<Node> minHeap = new PriorityQueue<>( (Node a, Node b) -> a.w - b.w );
        
        Map< Integer, ArrayList<Node> > adj = new HashMap<>();
        
        for(int[] edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(new Node(v, w));
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(new Node(u, w));
        }
        
        int[] dist = new int[V];
        Arrays.fill( dist, Integer.MAX_VALUE );
        
        dist[src] = 0;
        minHeap.add( new Node(src, 0) );
        
        while(!minHeap.isEmpty()){
            
            Node u = minHeap.remove();
            
            if(u.w > dist[u.v]) continue;
            
            for( Node node: adj.get(u.v) ){
                int v = node.v;
                int w = node.w;
                
                if( dist[v] > w + dist[u.v] ){
                    dist[v] = w + dist[u.v];
                    minHeap.add(new Node(v, dist[v]));
                }
                
            }
            
        }
        
        return dist;
        
    }
}