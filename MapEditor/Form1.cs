using Newtonsoft.Json;

namespace MapEditor
{
    [Serializable]
    public class Chunk
    {
        public List<int> edges = [];  // List of edges in the chunk
    }

    [Serializable]
    public class ChunkData
    {
        public List<Chunk> chunks = [];  // List of chunks
        private static readonly int[] ints1 = [];
        public static int[] Ints => ints1;  // Static array to hold chunk offsets
        public int[] chunkOffsets = Ints;

        public int gameMode;
    }

    public partial class Form1 : Form
    {
        private static readonly ChunkData chunkData = new();

        public Form1()
        {
            InitializeComponent();
            nudLink.Value = 1;
            this.Size = new Size(1000, 900);
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            UpdateChunkList();
        }

        // Button to add a new chunk
        private void BtnAddChunk_Click(object sender, EventArgs e)
        {
            // Create a new chunk using the values from the controls
            Chunk newChunk = new();

            // Add the new chunk to the chunk data
            chunkData.chunks.Add(newChunk);

            // Update the chunk list and ComboBox to reflect the new chunk
            UpdateChunkList();
            UpdateComboBox();
        }

        // Button to add a new edge
        private void BtnAddEdge_Click(object sender, EventArgs e)
        {
            if (lstChunks.SelectedItem != null)
            {
                var selectedChunk = chunkData.chunks[lstChunks.SelectedIndex];

                // Get the values from the numeric controls for link, texture, portal, x, y, portalLink, and portalIndex
                int link = (int)nudLink.Value;        // Value from nudLink (0-31, now 5 bits for link)
                int texture = (int)nudTexture.Value;  // Value from nudTexture (0-15)
                int x = (int)nudX.Value;              // Value from nudX (0-127 or your chosen range)
                int y = (int)nudY.Value;              // Value from nudY (0-127 or your chosen range)
                int portalLink = (int)nudPortalLink.Value;  // Value from nudPortalLink (0-31 or your chosen range)
                int portalChunkIndex = (int)chunkIndex.Value; // Value from nudPortalIndex (0-63 or your chosen range)

                // Pack the edge data using bitwise operations with a 5-bit link
                int edge_data = (int)(((link & 0x1F) << 28) |  // Now link uses 5 bits (0-31)
                                ((texture & 0xF) << 24)) |
                                ((x & 0x7F) << 17) | ((y & 0x7F) << 10) |
                                ((portalLink & 0x1F) << 6) | (portalChunkIndex & 0x3F);

                // Add the new edge to the selected chunk
                selectedChunk.edges.Add(edge_data);

                // Increment the link value for the next edge
                nudLink.Value = ((int)nudLink.Value) + 1;

                // Update the edge list for the selected chunk
                UpdateEdgeList();
            }
        }

        private void PanelVisualizer_Paint(object sender, PaintEventArgs e)
        {
            if (lstChunks.SelectedItem != null)
            {
                var selectedChunk = chunkData.chunks[lstChunks.SelectedIndex];

                // Create a Graphics object for drawing on the panel
                Graphics g = e.Graphics;

                // Optional: Set the drawing settings (background, line color, etc.)
                g.Clear(Color.White);  // Clear the panel with white color
                Pen pen = new(Color.Black, 2);  // Black lines, with thickness of 2

                // Loop through each edge in the selected chunk
                for (int i = 0; i < selectedChunk.edges.Count; i++)
                {
                    var edge = selectedChunk.edges[i];

                    var x = (int)((edge >> 17) & 0x7F);
                    var y = (int)((edge >> 10) & 0x7F);

                    // Draw the point representing the edge's position (x, y)
                    g.FillEllipse(Brushes.Red, x, y, 5, 5);  // Draw a small red dot

                    // If the edge has a "link" to another edge, connect them with a line
                    if (i + 1 < selectedChunk.edges.Count)
                    {
                        var nextEdge = selectedChunk.edges[i + 1];

                        var nx = (int)((nextEdge >> 17) & 0x7F);
                        var ny = (int)((nextEdge >> 10) & 0x7F);

                        g.DrawLine(pen, x + 2, y + 2, nx + 2, ny + 2);  // Draw a line from one edge to the next
                    }
                }
            }
        }

        // When a chunk is selected in the list, show its edges
        private void LstChunks_SelectedIndexChanged(object sender, EventArgs e)
        {
            UpdateEdgeList();
        }

        // Update the ListBox for chunks
        private void UpdateChunkList()
        {
            lstChunks.Items.Clear();
            int i = 0;
            foreach (var chunk in chunkData.chunks)
            {
                lstChunks.Items.Add($"index: {i++}");
            }
            i = 0;
            foreach (var chunk in chunkData.chunks)
            {
                chunkData.chunkOffsets[i++] = chunk.edges.Count;
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
                    int link = (edge >> 28) & 0x1F;             // Extract the 5 bits for link (bits 28-32)
                    int texture = (edge >> 24) & 0xF;          // Extract the 4 bits for texture (bits 24-27)
                    int x = (edge >> 17) & 0x7F;               // Extract the 7 bits for x (bits 17-23)
                    int y = (edge >> 10) & 0x7F;               // Extract the 7 bits for y (bits 10-16)
                    int portalLink = (edge >> 6) & 0x1F;       // Extract the 5 bits for portalLink (bits 6-9)
                    int portalChunkIndex = edge & 0x3F;        // Extract the 6 bits for portalChunkIndex (bits 0-5)

                    lstEdges.Items.Add($"Link: {link}, Texture: {texture}, Portal: {portalChunkIndex}, PortalLink: {portalLink}, X: {x}, Y: {y}");
                }
            }
            panelVisualizer.Invalidate();
        }

        // Save the chunk data to a JSON file
        private void BtnSaveToJson_Click(object sender, EventArgs e)
        {
            UpdateChunkList();
            UpdateEdgeList();

            SaveFileDialog saveFileDialog = new()
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
        private void BtnRemoveChunk_Click(object sender, EventArgs e)
        {
            if (lstChunks.SelectedItem != null)
            {
                chunkData.chunks.RemoveAt(lstChunks.SelectedIndex);
                UpdateChunkList();
                UpdateComboBox(); // Update ComboBox when a chunk is removed
            }
        }

        // Button to remove a selected edge
        private void BtnRemoveEdge_Click(object sender, EventArgs e)
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
                cmbChunks.Items.Add($"Chunk: {i + 1}");
            }

            // Optionally select the first chunk if the list is not empty
            if (cmbChunks.Items.Count > 0)
            {
                cmbChunks.SelectedIndex = 0;
            }
        }

        // When the ComboBox selection changes, update the edge list
        private void CmbChunks_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (cmbChunks.SelectedIndex >= 0)
            {
                lstChunks.SelectedIndex = cmbChunks.SelectedIndex; // Sync ListBox selection
                UpdateEdgeList();
            }
        }
    }
}
