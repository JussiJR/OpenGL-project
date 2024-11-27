using Newtonsoft.Json;

namespace MapEditor
{
    [Serializable]
    public class Chunk
    {
        public int floor;  // Floor height (0-255)
        public int roof;   // Roof height (0-255)
        public List<Edge> edges;  // List of edges in the chunk

        public Chunk(int floor, int roof)
        {
            this.floor = floor;
            this.roof = roof;
            edges = new List<Edge>();
        }
    }

    [Serializable]
    public class Edge
    {
        public int link;    // Link index (0-31)
        public int texture; // Texture value (0-255)
        public int portal;  // Portal height (0-255)

        public Edge(int link, int texture, int portal)
        {
            this.link = link;
            this.texture = texture;
            this.portal = portal;
        }
    }

    [Serializable]
    public class ChunkData
    {
        public List<Chunk> chunks;  // List of chunks

        public ChunkData()
        {
            chunks = new List<Chunk>();
        }
    }

    public partial class Form1 : Form
    {
        private ChunkData chunkData;

        public Form1()
        {
            InitializeComponent();
            chunkData = new ChunkData();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            UpdateChunkList();
        }

        // Button to add a new chunk
        private void btnAddChunk_Click(object sender, EventArgs e)
        {
            var newChunk = new Chunk(0, 0); // Default values for floor and roof
            chunkData.chunks.Add(newChunk);
            UpdateChunkList();
            UpdateComboBox(); // Update ComboBox to reflect the new chunk
        }

        // Button to add a new edge
        private void btnAddEdge_Click(object sender, EventArgs e)
        {
            if (lstChunks.SelectedItem != null)
            {
                var selectedChunk = chunkData.chunks[lstChunks.SelectedIndex];
                var newEdge = new Edge(0, 0, 0); // Default values for link, texture, portal
                selectedChunk.edges.Add(newEdge);
                UpdateEdgeList();
            }
        }

        // When a chunk is selected in the list, show its edges
        private void lstChunks_SelectedIndexChanged(object sender, EventArgs e)
        {
            UpdateEdgeList();
        }

        // Update the ListBox for chunks
        private void UpdateChunkList()
        {
            lstChunks.Items.Clear();
            foreach (var chunk in chunkData.chunks)
            {
                lstChunks.Items.Add($"Floor: {chunk.floor}, Roof: {chunk.roof}");
            }
        }

        // Update the ListBox for edges of the selected chunk
        private void UpdateEdgeList()
        {
            lstEdges.Items.Clear();
            if (lstChunks.SelectedItem != null)
            {
                var selectedChunk = chunkData.chunks[lstChunks.SelectedIndex];
                foreach (var edge in selectedChunk.edges)
                {
                    lstEdges.Items.Add($"Link: {edge.link}, Texture: {edge.texture}, Portal: {edge.portal}");
                }
            }
        }

        // Save the chunk data to a JSON file
        private void btnSaveToJson_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog
            {
                Filter = "JSON files (*.json)|*.json",
                DefaultExt = "json",
                FileName = "chunk_data.json"
            };

            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                string json = JsonConvert.SerializeObject(chunkData, Newtonsoft.Json.Formatting.Indented);
                File.WriteAllText(saveFileDialog.FileName, json);
                MessageBox.Show("Data saved successfully!");
            }
        }

        // Button to remove a selected chunk
        private void btnRemoveChunk_Click(object sender, EventArgs e)
        {
            if (lstChunks.SelectedItem != null)
            {
                chunkData.chunks.RemoveAt(lstChunks.SelectedIndex);
                UpdateChunkList();
                UpdateComboBox(); // Update ComboBox when a chunk is removed
            }
        }

        // Button to remove a selected edge
        private void btnRemoveEdge_Click(object sender, EventArgs e)
        {
            if (lstChunks.SelectedItem != null && lstEdges.SelectedItem != null)
            {
                var selectedChunk = chunkData.chunks[lstChunks.SelectedIndex];
                selectedChunk.edges.RemoveAt(lstEdges.SelectedIndex);
                UpdateEdgeList();
            }
        }

        // Update ComboBox to list the chunks by index or floor/roof values
        private void UpdateComboBox()
        {
            cmbChunks.Items.Clear();
            for (int i = 0; i < chunkData.chunks.Count; i++)
            {
                var chunk = chunkData.chunks[i];
                cmbChunks.Items.Add($"Chunk {i + 1}: Floor {chunk.floor}, Roof {chunk.roof}");
            }

            // Optionally select the first chunk if the list is not empty
            if (cmbChunks.Items.Count > 0)
            {
                cmbChunks.SelectedIndex = 0;
            }
        }

        // When the ComboBox selection changes, update the edge list
        private void cmbChunks_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (cmbChunks.SelectedIndex >= 0)
            {
                lstChunks.SelectedIndex = cmbChunks.SelectedIndex; // Sync ListBox selection
                UpdateEdgeList();
            }
        }
    }
}
