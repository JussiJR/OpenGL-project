using Newtonsoft.Json;

namespace MapEditor
{
    [Serializable]
    public class Chunk
    {
        public int floor;  // Floor height (0-255)
        public int roof;   // Roof height (0-255)
        public List<int> edges;  // List of edges in the chunk

        public Chunk(int floor, int roof)
        {
            this.floor = floor;
            this.roof = roof;
            edges = new List<int>(31);
        }
    }


    [Serializable]
    public class ChunkData
    {
        public List<Chunk> chunks;  // List of chunks
        public int[] chunkOffsets;

        public int gameMode;

        public ChunkData()
        {
            chunks = new List<Chunk>(15);
            chunkOffsets = new int[16];
        }
    }

    public partial class Form1 : Form
    {
        private ChunkData chunkData;

        public Form1()
        {
            InitializeComponent();
            chunkData = new ChunkData();
            nudLink.Value = 1;
            this.Size = new Size(1000, 900);

        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            UpdateChunkList();
        }

        // Button to add a new chunk
        private void btnAddChunk_Click(object sender, EventArgs e)
        {
            // Get the values from the NumericUpDown controls for floor and roof
            int floor = (int)nudFloor.Value;  // Value from nudFloor (0-255)
            int roof = (int)nudRoof.Value;    // Value from nudRoof (0-255)

            // Create a new chunk using the values from the controls
            var newChunk = new Chunk(floor, roof);

            // Add the new chunk to the chunk data
            chunkData.chunks.Add(newChunk);

            // Update the chunk list and ComboBox to reflect the new chunk
            UpdateChunkList();
            UpdateComboBox();
        }

        // Button to add a new edge
        private void btnAddEdge_Click(object sender, EventArgs e)
        {
            if (lstChunks.SelectedItem != null)
            {
                var selectedChunk = chunkData.chunks[lstChunks.SelectedIndex];

                // Get the values from the numeric controls for link, texture, portal, x, y, portalLink, and portalIndex
                int link = (int)nudLink.Value;        // Value from nudLink (0-31)
                int texture = (int)nudTexture.Value;  // Value from nudTexture (0-255)
                int portal = (int)nudPortal.Value;    // Value from nudPortal (0-255)
                int x = (int)nudX.Value;              // Value from nudX (0-1000 or your chosen range)
                int y = (int)nudY.Value;              // Value from nudY (0-1000 or your chosen range)
                int portalLink = (int)nudPortalLink.Value;  // Value from nudPortalLink (0-255 or your chosen range)
                int portalChunkIndex = (int)chunkIndex.Value; // Value from nudPortalIndex (0-255 or your chosen range)


                /**
                 * 
                 * Link 5, texture 4, X 7, Y 7, portal link 5, chunk 4  
                 * 
                 */

                // Create a new edge using the updated constructor with portalLink and portalIndex
                var newEdge = (int)(((link & 0x1F) << 27) | ((texture & 0xF) << 23)) | // Holy fk
                    ((x & 0x7F) << 16) | ((y & 0x7F) << 9) | ((portalLink & 0x1F) << 6 | (portalChunkIndex & 0x1F));

                // Add the new edge to the selected chunk
                selectedChunk.edges.Add(newEdge);

                nudLink.Value = ((int)nudLink.Value) + 1;

                // Update the edge list for the selected chunk
                UpdateEdgeList();
            }
        }

        private void panelVisualizer_Paint(object sender, PaintEventArgs e)
        {
            if (lstChunks.SelectedItem != null)
            {
                var selectedChunk = chunkData.chunks[lstChunks.SelectedIndex];

                // Create a Graphics object for drawing on the panel
                Graphics g = e.Graphics;

                // Optional: Set the drawing settings (background, line color, etc.)
                g.Clear(Color.White);  // Clear the panel with white color
                Pen pen = new Pen(Color.Black, 2);  // Black lines, with thickness of 2

                // Loop through each edge in the selected chunk
                for (int i = 0; i < selectedChunk.edges.Count; i++)
                {
                    var edge = selectedChunk.edges[i];

                    var x = (int)(edge >> 16) & 0x7f;
                    var y = (int)(edge >> 9) & 0x7f;

                    // Draw the point representing the edge's position (x, y)
                    g.FillEllipse(Brushes.Red, x, y, 5, 5);  // Draw a small red dot

                    // If the edge has a "link" to another edge, connect them with a line
                    if (i + 1 < selectedChunk.edges.Count)
                    {
                        var nextEdge = selectedChunk.edges[i + 1];


                        var nx = (int)(nextEdge >> 16) & 0x7f;
                        var ny = (int)(nextEdge >> 9) & 0x7f;


                        g.DrawLine(pen, x + 2, y + 2, nx + 2, ny + 2);  // Draw a line from one edge to the next
                    }
                }
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

            if (lstChunks.Items.Count > 0)
                chunkData.chunkOffsets[lstChunks.SelectedIndex == -1 ? 0 : lstChunks.SelectedIndex] =
                    chunkData.chunks[lstChunks.SelectedIndex == -1 ? 0 : lstChunks.SelectedIndex].edges.Count;
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

                    uint link = (edge >> 27) & 0x1F;           // Extract the 5 bits for link
                    uint texture = (edge >> 23) & 0xF;         // Extract the 4 bits for texture
                    uint x = (edge >> 16) & 0x7F;              // Extract the 7 bits for x
                    uint y = (edge >> 9) & 0x7F;               // Extract the 7 bits for y
                    uint portalLink = (edge >> 6) & 0x1F;      // Extract the 5 bits for portalLink
                    uint portalChunkIndex = edge & 0xF;         // Extract the 4 bits for portalChunkIndex

                    lstEdges.Items.Add($"Link: {link}, Texture: {texture}, Portal: {portalChunkIndex}, PortalLink: {portalLink}, X: {x}, Y: {y}");
                }
            }
            panelVisualizer.Invalidate();
        }

        // Save the chunk data to a JSON file
        private void btnSaveToJson_Click(object sender, EventArgs e)
        {

            UpdateChunkList();
            UpdateEdgeList();

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

